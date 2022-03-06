#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <mcp_can.h>
#include <SD.h>
#include <SPI.h>

#include "display.h"
#include "statusBar.h"
#include "menu.h"
#include "mainPage.h"
#include "touchInput.h"
#include "canbus.h"
#include "sdcard.h"

mainPage mainpage = mainPage();
touchInput touchinput = touchInput();
canBusInterface can = canBusInterface();
flashDrive sdCard = flashDrive();
unsigned char Flag_Recv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

// event fucntions
void clearTextBox(){
        mainpage.textbox.clear();
        mainpage.statusbar.printStatus("Cleared textBox!");
}

void onPressConnect(){
    mainpage.statusbar.printStatus("Connected");
    can.connect();
    mainpage.changeMenu(&mainpage.Menu2);

}

void onPressDisconnect(){
   can.disconnect();
    mainpage.statusbar.printStatus("Disconnected!");
    mainpage.changeMenu(&mainpage.mainMenu);
}
 

void onCanConnect(){

}

void onCanFail(){

}

void onCanMsgRead(){
 buffer_T canbuf = can.getBuffer();
 for (size_t i = 0; i < canbuf.len ; i++)
 {
  sdCard.writeFile("log.txt",(char*)canbuf.data[i] );
 }
 
   

}
void item2press(){
 
    mainpage.statusbar.printStatus("Menu Change");
    mainpage.changeMenu(&mainpage.mainMenu);
}

void onSdCardInserted(){
    mainpage.textbox.print("SD Card Inserted!");
    Serial.println("Inserted");
}
void onSdCardremove(){
    mainpage.textbox.print("SD Card Removed!");
    Serial.println("REMOIVED");
}
#endif