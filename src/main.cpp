#include "main.h"

void setup(){
        Serial.begin(9600);
        screen_init();
        mainPageInit(&screen);
        mainPage.draw();
        }

void loop(){
                
     delay(2100);
    
}