#include "touchInput.h"

touchInput::touchInput(){
    _screen = NULL;
}

touchInput::~touchInput()
{
    
}
void touchInput::init(Elegoo_GFX* screen){
    _screen = screen;
}

bool touchInput:: check()
{
    //digitalWrite(13, HIGH);
    _point = _tScreen.getPoint();
   // digitalWrite(13, LOW);
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    if (_point.z > MINPRESSURE && _point.z < MAXPRESSURE) {
        // scale from 0->1023 to tft.width
        _point.x = map(_point.x, TS_MINX, TS_MAXX, _screen->width(), 0);
        _point.y = (_screen->height()-map(_point.y, TS_MINY, TS_MAXY, _screen->height(), 0));
        return true;
   }
   return false;
}

TSPoint touchInput::getPoint() const {return _point;}