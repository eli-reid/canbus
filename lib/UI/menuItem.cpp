#include "menuItem.h"
menuItem::menuItem(Elegoo_GFX* display, int index, int width, String title):_title(title){
    _display=display;
    _index=index;
    _w=width;
    _name=_title;
}

void menuItem::draw(){
    int adjustment = _h/2 * 6 / 10 + 1;
    _display->setTextSize(_textSize);
    _display->setTextColor(_textColor);
    _display->fillRect(_x,_y,_w,_h, BLUE);
    _display->setCursor(_x+3,_y + adjustment);
    _display->print(_title);
}

int menuItem::getIndex() const{ return _index; }
int16_t menuItem::getHeight() const{ return _h; } 
int16_t menuItem::getWidth() const{ return _w; }
int16_t menuItem::getX() const{ return _x; }
int16_t menuItem::getY() const{ return _y; } 
void menuItem::setX(int16_t x){ _x = x;}
void menuItem::setY(int16_t y){ _y = y;}
void menuItem::setWidth(int16_t w){ _w = w; }
void menuItem::setHeight(int16_t h){ _h = h; }