#include "menu.h"
Menu::Menu(Elegoo_GFX *display, String name, int16_t h, int16_t w, int8_t textSize, bool visible,
    bool border, int location, uint16_t borderColor, uint16_t fillColor, uint16_t textColor ){
    _w = w;
    _h = h;
    _x = 0;
    _y = location ? _display->height()-_h : 0;
    _name = name;
    _textSize =  textSize;
    _visible = visible;
    _location =  location; 
    _display = display;
    _fillColor = fillColor;
    _borderColor = borderColor;
    _textColor = textColor;     
}

void Menu::draw(){
    Item::draw();
    drawMenuItems();    
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

void Menu::addMenuItem(menuItem *m){
    int index = m->getIndex();
    m->setHeight(_h - 6);
    _menuitems[index] = m;
    m->setY(_y + 3);
    if(m->getIndex()>0){
        menuItem *prevMI = _menuitems[index-1];
        m->setX(_x + prevMI->getX() + prevMI->getWidth() + 3);
    }
    else{
        m->setX(_x+3);
    }
    _menuItemIndex++;
}

void Menu::drawMenuItems(){
    for(int i=0; i < _menuItemIndex; i++)
        _menuitems[i]->draw();
}

void Menu::press(int16_t x, int16_t y){
    Item::press( x, y);
    if(this->isPressed()){
        for(int i=0; i < _menuItemIndex; i++)
            _menuitems[i]->press(x,y);
    }
}