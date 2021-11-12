#include "statusBar.h"
statusBar::statusBar(){
    
}
statusBar::statusBar(Elegoo_GFX  *display, 
        int16_t h, int16_t w, 
        int8_t textSize, 
        bool visible, 
        bool border, 
        location_enum loc=BOTTOM, 
        uint16_t borderColor=BLUE, 
        uint16_t fillColor = WHITE, 
        uint16_t textColor = BLUE){

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

statusBar::~statusBar()
{
}

void statusBar::printStatus()
{  

    Serial.println(_status);
    _display->setTextSize(_textSize);
    _display->setTextColor(_textColor);
    if(_location == BOTTOM)
        _display->setCursor(2,_display->height()-14); 
   
    _display->print(_status);
    return;
}

void statusBar::printStatus(String status){
    setStatus(status);
    printStatus();

}


void statusBar::setStatus(String status)
{   
    clear();
    Serial.println("status updated"); 
    _status = status;
    return;
}
void statusBar::clear(){
        if(_location == BOTTOM)
    {
        _display->fillRect(1,_display->height()-_h-1,_w-2,_h-2, _fillColor);
    }
    else
    {
        _display->fillRect(1,1,_w-2,_h-2, _fillColor);
    }
}
void statusBar::draw() {
    if(_location == BOTTOM)
    {
        _display->drawRect(0,_display->height()-_h,_w,_h, _borderColor);
        _display->fillRect(1,_display->height()-_h-1,_w-2,_h-2, _fillColor);
    }
    else
    {
        _display->drawRect(0,0,_w,_h,_borderColor);
        _display->fillRect(1,1,_w-2,_h-2, _fillColor);
    }
    return;

}