#include "item.h"


void Item::draw() {
 
}

void Item::setTextColor(int16_t color){
    
}

void Item::setTextSize(int16_t size){
    
}

void Item::setFillColor(int16_t color){

}

void Item::fill(){
    
}

void Item::fill(int16_t color){

}

void Item::setIndex(int index){
    _index = index;
}

boolean Item::contains(int16_t x, int16_t y) {
  if ((x <(_x - _w)) || (x > (_x + _w))) return false;
  if ((y < (_y - _h)) || (y > (_y + _h))) return false;
 /*  Serial.println("*************** ITEM::CONTIANS********************");
  Serial.print("X= "); Serial.print(x); Serial.print(" < ");Serial.print(_x - _w);Serial.print(" > ");Serial.println((_x + _w));
  Serial.print("Y= "); Serial.print(y); Serial.print(" < ");Serial.print((_y - _h));Serial.print(" > ");Serial.println((_y + _h)); */
  Serial.print(_name); Serial.println(" stop touchng me");
  return true;
 }

 void Item::press(int16_t x, int16_t y) {
   laststate = currstate;
   currstate =  contains(x,y);
 }

 boolean Item::isPressed() { return currstate; }

 boolean Item::justPressed() { return (currstate && !laststate); }

 boolean Item::justReleased() { return (!currstate && laststate); }

void Item::setName(String name){
  _name = name;
}

String Item::getName() const{
  return _name;
}