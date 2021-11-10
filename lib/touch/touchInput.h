#ifndef _TOUCHINPUT_H
#define _TOUCHINPUT_H
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
#define TS_MINY 70
#define TS_MAXY 920
#define TS_MINX 120
#define TS_MAXX 900
#define MINPRESSURE 10
#define MAXPRESSURE 1000
#include <Elegoo_TFTLCD.h> 
#include "TouchScreen.h"

class touchInput
{
private:
    TSPoint _point;
    TouchScreen _tScreen;
    Elegoo_TFTLCD _screen;
public:
    touchInput();
    touchInput(Elegoo_TFTLCD* screen);
    ~touchInput();
    
    bool check();
};







#endif // MACRO


