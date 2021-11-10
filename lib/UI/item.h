#ifndef _ITEM_H
#define _ITEM_H
#include <stdint.h>
#include <string.h>
#include "Elegoo_GFX.h"
#include "colors_dfs.h"
enum location_enum {TOP,BOTTOM};

class Item
{
    protected:
        int16_t _w, _h, 
                _x, _y, 
                _fillColor, 
                _borderColor,   
                _textColor, 
                _textSize,
                _index;
        boolean currstate, laststate;
        bool _visible, _border;
        String _status;
        Elegoo_GFX  *_display;
public:
    Item();
    ~Item();
    virtual void draw();

    void setTextColor(int16_t color);
    void setTextSize(int16_t size);
    void setFillColor(int16_t color);
    
    void fill();
    void fill(int16_t color);
    boolean contains(int16_t x, int16_t y);
    void press(boolean p);
    boolean isPressed();
    boolean justPressed();
    boolean justReleased();
    void setIndex(int index);
 

    //TODO: add event functions
};






#endif 
