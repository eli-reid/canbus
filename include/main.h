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

mainPage mainpage = mainPage();
touchInput touchinput = touchInput();
canBusInterface can = canBusInterface();

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
    can.connect();
 
}
 

void onCanConnect(){

}

void onCanFail(){

}

void onCanMsgRead(){


}

#endif