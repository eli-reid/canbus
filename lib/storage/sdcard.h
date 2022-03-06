#ifndef _SDCARD_H
#define _SDCARD_H
#define SOFTWARE_SPI
#include <stdio.h>
#include <iostream>
#include <SPI.h>
#include <utility/Sd2Card.h>
#include <utility/SdFat.h>
#include <utility/FatStructs.h>

enum FILE_ERR_E{
    NONE,
    WR_ERR_FLG,
    RD_ERR_FLG,
    OP_ERR_FLG
};

class flashDrive
{
    private:
        Sd2Card _card;
        SdVolume _vol;
        SdFile  _root;
        int chipSelect;

        FILE_ERR_E FILE_ERR;
        bool _currstate=false, _laststate=false;
        bool _justInserted()  const{ return (_currstate && !_laststate); }
        bool _justRemoved()  const{ return (!_currstate && _laststate); }
        void _eventChange();

    public:
        void(*onInserted)(void) = [](void){};
        void(*onRemoved)(void) = [](void){};
        flashDrive(int chipselect = SD_CHIP_SELECT_PIN);
        bool writeFile(char *fileName, char *data);
        int readFile(char *file, String *readBuffer);
        //bool writeFile();
        bool cardPresent();
        bool checkForCard();
};

#endif