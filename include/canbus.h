#ifndef _CANBUS_H
#define _CANBUS_H

#define CAN_2515
#define MAX_DATA_SIZE 8

#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;
typedef struct BUFFER{
    unsigned char len = 0;
    unsigned char data[8];
}buffer_T;

class canBusInterface{
  private:
    MCP_CAN _can = MCP_CAN(SPI_CS_PIN);
    bool _connected = false;
    bool _msgFlag = false;
    buffer_T _buffer;
    void _onMsgRead();
    void _onMsgRecv();
  public:
    //event methods
    void(*onConnect)(void) = [](void){};
    void(*onDisconnect)(void) = [](void){};
    void(*onFail)(void) = [](void){};
    void(*onMsgRecv)(void) = [](void){};
    void(*onSendMsg)(void) = [](void){};
    // methods
    void connect();
    void disconnect();
    void msgCheck();
    void msgRead();
    //getters
    buffer_T getBuffer(){return _buffer;}
    bool isConnected(){return _connected;};
};
#endif