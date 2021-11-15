#ifndef _TOUCHINPUT_H
#define _TOUCHINPUT_H
#include <Elegoo_TFTLCD.h>
#include <Elegoo_GFX.h> 
#include "TouchScreen.h"

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

class touchInput
{
private:
    TSPoint _point;
    TouchScreen _tScreen = TouchScreen(XP, YP, XM, YM, 300);
    Elegoo_GFX *_screen;
public:
    touchInput();
    void init(Elegoo_GFX* screen);
    ~touchInput();
    TSPoint getPoint();
    bool check();
};







#endif // MACRO


