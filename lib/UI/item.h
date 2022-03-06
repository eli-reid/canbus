#ifndef _ITEM_H
#define _ITEM_H
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "Elegoo_GFX.h"
#include "colors_dfs.h"
enum location_enum {TOP, BOTTOM};

class Item
{
    protected:
        int16_t _w=0, _h=0, 
                _x=0, _y=0, 
                _fillColor=0, 
                _borderColor=0,   
                _textColor=0, 
                _textSize=1,
                _index=0;
        bool currstate=false, laststate=false;
        bool _visible=true, _border=true;
        String _name = "";
        Elegoo_GFX  *_display=NULL;
public:
    void(*onPress)(void) = [](void){};
    virtual void draw();
    void setTextColor(int16_t color);
    void setTextSize(int16_t size);
    void setFillColor(int16_t color);
    void setName(String name);
    String getName() const;
    virtual void fill();
    virtual void fill(int16_t color);
    bool contains(int16_t x, int16_t y);
    virtual void press(int16_t x, int16_t y);
    bool isPressed() const;
    bool justPressed() const;
    bool justReleased() const;
    void setIndex(int index);
    int getIndex() const {return _index;}
};
#endif