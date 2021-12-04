#include "menu.h"
Menu::Menu(){}
Menu::Menu  (Elegoo_GFX  *display, String name,
        int16_t h, int16_t w, 
        int8_t textSize, 
        bool visible, 
        bool border, 
        location_enum loc=TOP, 
        uint16_t borderColor=BLUE, 
        uint16_t fillColor = WHITE, 
        uint16_t textColor = BLUE)
{
    _w = w;
    _h = h;
    _x=0;
    _y= loc ? _display->height()-_h : 0;
    _name = name;
    _textSize =  textSize;
    _visible = visible;
    _location =  loc; 
    _display = display;
    _fillColor = fillColor;
    _borderColor = borderColor;
    _textColor = textColor;     
}

Menu::~Menu()
{
}

void Menu::print(String p){
    _display->setTextSize(_textSize);
    _display->setTextColor(_textColor);

    if(_location == BOTTOM)
        _display->setCursor(2,_display->height()-14); 
    else
        _display->setCursor(2,10);

    _display->print(p);
}