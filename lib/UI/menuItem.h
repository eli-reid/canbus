#ifndef _MENUITEM_H
#define _MENUITEM_H
#include <stdint.h>
#include <stdbool.h>
#include "colors_dfs.h"
#include "Arduino.h"
#include "item.h"

class menuItem : public Item
{
private:
    int _index;
    String _title;

public:
    int getIndex();
    menuItem(/* args */){};
    menuItem(Elegoo_GFX * display, int index, int width, String title);
    void setHeight(int16_t h);
    int16_t getHeight();
    void setWidth(int16_t w);
    int16_t getWidth();
    void setX(int16_t x);
    void setY(int16_t y);
    int16_t getX();
    int16_t getY();
    void draw();
    ~menuItem(){};
};
#endif