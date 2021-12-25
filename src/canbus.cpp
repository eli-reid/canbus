#include "canbus.h"

void canBusInterface::connect(){
    while (CAN_OK != _can.begin(CAN_500KBPS)) { // init can bus : baudrate = 500k
        onFail();
     }
    _connected = true;
    onConnect();

}

void canBusInterface::disconnect(){
    _connected = false;
    onDisconnect();
}

void canBusInterface::msgCheck(){
    if(CAN_MSGAVAIL == _can.checkReceive()){
        _msgFlag=true;
        _onMsgRecv();
        onMsgRecv();
    }
   
}

void canBusInterface::msgRead(){
      _can.readMsgBuf(&_buffer.len, _buffer.data);
      _onMsgRead();

}
void canBusInterface::_onMsgRead(){

}

void canBusInterface::_onMsgRecv(){
    msgRead();


}