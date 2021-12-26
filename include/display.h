#ifndef _screen_H
#define _screen_H
//setup pins
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

//includes
#include "Elegoo_GFX.h"
#include "Elegoo_TFTLCD.h"
#include "colors_dfs.h"

//gobal utility functions
void screen_init();
extern Elegoo_TFTLCD screen;
#endif