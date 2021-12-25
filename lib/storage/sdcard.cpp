#include "sdcard.h"

flashDrive::flashDrive(int chipselect){
    chipSelect = chipselect;

}

bool flashDrive::cardPresent(){
    return fdrive.begin(chipSelect);
}

int flashDrive::writeFile(String file, String data){
    int err = NONE;
    File dataFile;
    if(cardPresent()){
         dataFile = fdrive.open(file, FILE_WRITE);
        if(dataFile){
            dataFile.println(data);
        }
        else{
            err = WR_ERR_FLG;  
        }
    }
    else{
        err = OP_ERR_FLG;  
    } 
    dataFile.close();
    fdrive.end();
    return err;
}

int flashDrive::readFile(String file, String *readBuff){
    int err = NONE;
    if(cardPresent()){
        File dataFile = fdrive.open(file, FILE_READ);
        if(dataFile){
            *readBuff = dataFile.readString();
        }
        else{
            err = WR_ERR_FLG;  
        }
    }
    else{
        err = OP_ERR_FLG;  
    } 

    return err;
}
