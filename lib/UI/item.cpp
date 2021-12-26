#include "item.h"

void Item::draw() {
  _display->fillRect(_x,_y,_w,_h, _fillColor);
  _display->drawRect(_x,_y,_w,_h, _borderColor);
}

void Item::setTextColor(int16_t color){
  _textColor = color;
}

void Item::setTextSize(int16_t size){
  _textSize = size;
}

void Item::setFillColor(int16_t color){
  _fillColor = color;
}

void Item::fill(){
  draw();
}

void Item::fill(int16_t color){
  _display->fillRect(_x,_y,_w,_h, color);
  _display->drawRect(_x,_y,_w,_h, _borderColor);
}

void Item::setIndex(int index){
  _index = index;
}

void Item::setName(String name){
  _name = name;
}

String Item::getName() const{
  return _name;
}

bool Item::contains(int16_t x, int16_t y) {
  if ((x < (_x - _w)) || (x > (_x + _w))) return false;
  if ((y < (_y - _h)) || (y > (_y + _h))) return false;
  return true;
 }

 void Item::press(int16_t x, int16_t y) {
  laststate = currstate;
  currstate =  contains(x,y);
  if(currstate)
    onPress();
 }

 boolean Item::isPressed() { return currstate; }

 boolean Item::justPressed() { return (currstate && !laststate); }

 boolean Item::justReleased() { return (!currstate && laststate); }
