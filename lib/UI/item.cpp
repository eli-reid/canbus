#include "item.h"

Item::Item(/* args */)
{
}

Item::~Item()
{
}

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

  //if ((x < (_x - _w/2)) || (x > (_x + _w/2))) return false;
   Serial.println("trying to touch me");
   if ((y < (_y - _h/2)) || (y > (_y + _h/2))) return false;
   Serial.println("stop touchng me");
   return true;
 }

 void Item::press(boolean p) {
      Serial.println(p);
   laststate = currstate;
   currstate = p;

 }

 boolean Item::isPressed() { return currstate; }

 boolean Item::justPressed() { return (currstate && !laststate); }

 boolean Item::justReleased() { return (!currstate && laststate); }
