#ifndef _SDCARD_H
#define _SDCARD_H

#include <stdio.h>
#include <iostream>
#include <SD.h>
#include <SPI.h>
enum FILE_ERR_E{
    NONE,
    WR_ERR_FLG,
    RD_ERR_FLG,
    OP_ERR_FLG
};

class flashDrive
{
    private:
        int chipSelect;
        SDLib::SDClass fdrive;
        FILE_ERR_E FILE_ERR;

    public:
        flashDrive(int chipselect = 4);
        int writeFile(String file, String data);
        int readFile(String file, String *readBuffer);
        bool cardPresent();

};

#endif