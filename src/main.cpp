#include "main.h"
int16_t tx,ty;
mainPage mp = mainPage();
touchInput ti = touchInput();
void setup(){
        
        Serial.println("*************** SETUP ********************");

        screen_init();
        Serial.begin(9600);
        ti.init(&screen);
        mp.init(&screen);
        mp.draw();
        Serial.println("*************** SETUP COMPLETE ********************");
       
        }

void loop(){
      if(ti.check()) {

        tx = ti.getPoint().x;
        ty = ti.getPoint().y;
        mp.contains(tx,ty);
 
      }        
     delay(100);
    
}