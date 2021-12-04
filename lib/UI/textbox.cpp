#include "textBox.h"
//using namespace std;
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
    _maxLines = _h/10; 
    _currentCursorX = _x + 3;
    _currentCursorY = _y + 3;
}

textBox::textBox(/* args */)
{
}
void textBox::update(){

}

void textBox::print(String text){
    bool redraw = false;


    _display->setCursor(_currentCursorX,_currentCursorY);
    _display->setTextColor(_textColor);
    _display->setTextSize(_textSize);
    _display->setTextWrap(false);

    for(int i = 0; i<text.length(); i+=39){
        if(text.substring(i,i+39).length()>0)
            _lines.push_back(text.substring(i,i+39));
            
        if(_lines.size()>_maxLines){
            _lines.pop_front();
            redraw=true;
        }
        else{
            _display->setCursor(_currentCursorX,_currentCursorY);
            _display->println(_lines.back());
            _currentCursorY = _display->getCursorY();
        }
        
    }

    if(redraw) {
        _currentCursorY = _y+3;
        _display->setCursor(_currentCursorX,_currentCursorY);
        draw();
        for(list<String>::iterator _itr = _lines.begin(); _itr!=_lines.end(); _itr++) {   
            _display->println(*_itr);
            Serial.print("redraw");Serial.println(_currentCursorY);     
        }
    }
}

textBox::~textBox()
{
}

