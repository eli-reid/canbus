#include "statusBar.h"
statusBar::statusBar(){
    
}
statusBar::statusBar(Elegoo_GFX  *display, String name, 
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

statusBar::~statusBar()
{
}

void statusBar::printStatus()
{  

    Serial.println(_status);
    _display->setTextSize(_textSize);
    _display->setTextColor(_textColor);
    int adjustment = _h/2 * 6 / 10 + 1;
     Serial.println(adjustment);
    _display->setCursor(_x+3,_y + adjustment); 
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
    _hasStatus = true;
    return;
}
void statusBar::clear(){
    draw();
    _hasStatus = false;
}
void statusBar::fill(){
    fill();
    if(_hasStatus)
        printStatus();
}

void statusBar::fill(int16_t color){
    fill(color);
    if(_hasStatus)
        printStatus();
}