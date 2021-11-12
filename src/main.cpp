#include "main.h"
mainPage mainpage;
touchInput ti;
void setup(){
        Serial.begin(9600);
        screen_init();
        touchInput ti(&screen);
        mainPage mainpage(&screen);
        mainpage.draw();
        }

void loop(){
      if(ti.check()) {
        Serial.println("t");
        int16_t x=ti.getPoint().x;
        int16_t y= ti.getPoint().y;
        mainpage.menu.contains(x,y);
        mainpage.contains(x,y);
        delete &x, &y;         
            
      }        
     delay(100);
    
}