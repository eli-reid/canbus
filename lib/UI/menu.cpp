#include "menu.h"
Menu::Menu(){}
Menu::Menu  (Elegoo_GFX  *display, 
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
void Menu::draw(){
    if(_location == BOTTOM)
    {   
        _x=0;
        _y = _display->height()-_h;
        _display->drawRect(0,_display->height()-_h,_w,_h, _borderColor);
        _display->fillRect(1,_display->height()-_h-1,_w-2,_h-2, _fillColor);

    }
    else
    {
        _x=0;
        _y=0;
        _display->drawRect(0,0,_w,_h,_borderColor);
        _display->fillRect(1,1,_w-2,_h-2, _fillColor);
        
    }
    return;
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