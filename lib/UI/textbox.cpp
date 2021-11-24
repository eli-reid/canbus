#include "textBox.h"
using namespace std;
textBox::textBox (Elegoo_GFX  *display, String name, int16_t h, int16_t w, int8_t textSize, bool visible, bool border, int16_t x, int16_t y , 
        uint16_t borderColor=BLUE,   uint16_t fillColor = BLACK, uint16_t textColor = WHITE){
    _w = w;
    _h = h;
    _x=x;
    _y=y;
    _name = name;
    _textSize =  textSize;
    _visible = visible;
    _display = display;
    _fillColor = fillColor;
    _borderColor = borderColor;
    _textColor = textColor;     
}

textBox::textBox(/* args */)
{
    lines.push_front("eli");
    
}
void textBox::update(){

}

void textBox::draw(){

}

void print(String text){
    
}

textBox::~textBox()
{
}

