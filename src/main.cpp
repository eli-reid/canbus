#include "main.h"
int16_t tx,ty;
mainPage mp = mainPage();
touchInput ti = touchInput();
#include "canbus.h"

void setup(){
        mcp2515_can CAN(SPI_CS_PIN);
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