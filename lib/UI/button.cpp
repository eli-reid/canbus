#include "button.h"
button::button(Elegoo_GFX  *display, int16_t x, int16_t y, int16_t h, int16_t w,
                    char *label, int8_t textSize, bool visible, uint16_t borderColor=BLUE, 
                    uint16_t fillColor = WHITE, uint16_t textColor = BLUE)
{
    button::init(display,x,y,h,w,label,textSize,visible, borderColor,fillColor , textColor);

}
button::button(){
    _init = false;
}

button::~button()
{
}

void button::drawButton()
{


}
void button::init(Elegoo_GFX  *display, int16_t x, int16_t y, int16_t h, int16_t w,
                    char *label, int8_t textSize, bool visible, uint16_t borderColor=BLUE, 
                    uint16_t fillColor = WHITE, uint16_t textColor = BLUE)
            {
                _x = x;
                _y = y;
                _w = w;
                _h = h;
                
                _visible = visible; 
                _display = display;
                _fillColor = fillColor;
                _borderColor = borderColor;
                _textSize =  textSize;
                _textColor = textColor;
                _label = label;


            }
