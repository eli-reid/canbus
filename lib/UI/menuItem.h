#ifndef _MENUITEM_H
#define _MENUITEM_H
#include <string.h>
#include <stdint.h>

class menuItem
{
private:
    int _index;
    int16_t _width;
    int16_t _height;
    //String _title;
public:
    menuItem(/* args */);
    void setHeight(int16_t h);
    int16_t getHeight();
    bool contains(int16_t x,int16_t y);
    ~menuItem();
};







#endif