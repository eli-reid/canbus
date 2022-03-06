#ifndef _TEXTBOX_H
#define _TEXTBOX_H

using namespace std;
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "item.h"
class textBox : public Item
{
private:
    list<String> _lines;
    uint8_t _maxLines;
    int _maxChar=38;
    int16_t _currentCursorY;
    int16_t _currentCursorX;

public:
    textBox(Elegoo_GFX  *display, String name, int16_t h, int16_t w, int8_t textSize, bool visible, bool border, int16_t x, int16_t y , 
        uint16_t borderColor=BLUE, uint16_t fillColor=BLACK, uint16_t textColor=WHITE);
    textBox(){};
    ~textBox(){};
    void clear();
    void print(String text);
};
#endif  