#include "display.h"
Elegoo_TFTLCD screen(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
uint16_t identifier = screen.readID();
void screen_init(){
    screen.reset();
    screen.begin(identifier);
    screen.setRotation(2);
    screen.fillScreen(BLACK);
}