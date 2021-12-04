#include "main.h"
int16_t tx,ty;
mainPage mp = mainPage();
touchInput ti = touchInput();
#include "canbus.h"
#include <mcp_can.h>

void setup(){
  MCP_CAN CAN(SPI_CS_PIN);
  Serial.begin(9600);
  while (!SERIAL_PORT_MONITOR) {}
  Serial.println("*************** SETUP ********************");
  #if MAX_DATA_SIZE > 8
    CAN.setMode(CAN_NORMAL_MODE);
  #endif
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
    SERIAL_PORT_MONITOR.println(F("CAN init fail, retry..."));
    delay(100);
  }
  screen_init();

  ti.init(&screen);
  mp.init(&screen);
  mp.draw();
  mp.sb.printStatus("testing 1 2 3 4");
  mp.tb.print("123456");
  mp.tb.print("12345678901234567890123456789012345678");
  mp.tb.print("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
   mp.tb.print("123456");
  mp.tb.print("12345678901234567890123456789012345678");
  mp.tb.print("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
   mp.tb.print("123456");
  mp.tb.print("12345678901234567890123456789012345678");
  mp.tb.print("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
   mp.tb.print("123456");

  Serial.println("*************** SETUP COMPLETE ********************");
  
}

void loop(){
  if(ti.check()) 
    mp.contains(ti.getPoint().x,ti.getPoint().y);     
  delay(100);
}