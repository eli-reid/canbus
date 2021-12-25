#include "main.h"

void setup(){

  Serial.begin(9600);
  screen_init();
  touchinput.init(&screen);
  mainpage.init(&screen);
  mainpage.draw();
  mainpage.statusbar.printStatus("Not Connected");
  mainpage.menuitem1.onPress = onPressConnect;
}

void loop(){
  if(touchinput.check()) 
    mainpage.contains(touchinput.getPoint().x,touchinput.getPoint().y);

  if (can.isConnected())
    can.msgCheck();  
  
  delay(100);
}
