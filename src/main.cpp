#include "main.h"

int i = 0;
void setup(){
  Serial.begin(9600);
  screen_init();
  touchinput.init(&screen);
  mainpage.init(&screen);
  mainpage.draw();
  mainpage.statusbar.printStatus("Not Connected");
  mainpage.canConnectMenuItem.onPress = onPressConnect;
  mainpage.item2.onPress = item2press;
  mainpage.item1.onPress = onPressDisconnect;
  sdCard.onInserted = onSdCardInserted;
  sdCard.onRemoved = onSdCardremove;
  can.onMsgRecv = onCanMsgRead;
}
 
void loop(){
  if(touchinput.check()) 
    mainpage.contains(touchinput.getPoint().x,touchinput.getPoint().y);

  if (can.isConnected())
    can.msgCheck();  
  sdCard.checkForCard();

  delay(10);
}
