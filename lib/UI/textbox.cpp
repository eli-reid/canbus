#include "textBox.h"
//using namespace std;
textBox::textBox (Elegoo_GFX  *display, String name, int16_t h, int16_t w, int8_t textSize, bool visible, bool border, int16_t x, int16_t y , 
        uint16_t borderColor,   uint16_t fillColor, uint16_t textColor){
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
    _maxLines = _h/8.3; 
    _currentCursorX = _x + 6;
    _currentCursorY = _y + 3;
}

void textBox::print(String text){
    bool redraw = false;
    _display->setCursor(_currentCursorX,_currentCursorY);
    _display->setTextColor(_textColor);
    _display->setTextSize(_textSize);
    _display->setTextWrap(false);

    for(unsigned int i = 0; i<text.length(); i+=_maxChar){
        if(text.substring(i,i+_maxChar).length()>0)
            _lines.push_back(text.substring(i,i+_maxChar));
            
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
            _display->flush();   
            _display->setCursor(_currentCursorX,_currentCursorY);
            _display->println(*_itr);
            _currentCursorY = _display->getCursorY();    
        }
    }
}

void textBox::clear(){
    _currentCursorY = _y+3;
    _lines.clear();
    draw();
}