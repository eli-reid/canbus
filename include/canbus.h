#ifndef _CANBUS_H
#define _CANBUS_H

#define CAN_2515
#define MAX_DATA_SIZE 8

#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;



class canBusInerface{
  private:
    mcp2515_can *can;


};
#endif