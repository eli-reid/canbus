#include "sdcard.h"

flashDrive::flashDrive(int chipselect){
    chipSelect = chipselect;
}

bool flashDrive::cardPresent(){
    return _currstate;
}

 bool flashDrive::checkForCard(){
    _laststate = _currstate;        
    if(_card.init(SPI_FULL_SPEED, SD_CHIP_SELECT_PIN) && _vol.init(&_card))
        _currstate = true;
    else
        _currstate = false;
    _eventChange();
    return _currstate;    
}

void flashDrive::_eventChange(){
    if(_justInserted())
        onInserted();
    if(_justRemoved())
        onRemoved();    
}


int flashDrive::readFile(char* file, String *readBuffer){
    if(cardPresent()){
        SdFile f;
        uint16_t BUF;
        f.read(&BUF,1);}
}
bool flashDrive::writeFile(char *fileName, char *data){
    SdFile file;
    if(cardPresent()){
         if(_root.isOpen()) 
                _root.close();
            if(_root.openRoot(&_vol)) 
                if(file.open(&_root, fileName, O_CREAT | O_WRITE ))
                {
                    file.seekEnd();
                    file.println(data);
                    file.close();
                }  
    }
    return true;
}