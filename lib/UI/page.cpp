#include "Page.h"
#include <string.h>
 
Page::Page(/* args */)
{
    _itemIndex=0;
}

Page::~Page()
{
}

void Page::addItem(Item *item){
    Serial.println("*************** PAGE::ADDITEM********************");
    Serial.print("_itemtindex = ");Serial.println(this->_itemIndex);
    items[this->_itemIndex] = item;
    item->setIndex(this->_itemIndex);
    Serial.print("item added= ");Serial.println("");
    this->_itemIndex++;
    Serial.print("_itemtindex = ");Serial.println(this->_itemIndex);
}

void Page::removeItem(int index){
    
}

void Page::draw(){
    Serial.println("*************** PAGE::DRAW********************");
    Serial.print("_itemtindex = ");Serial.println(this->_itemIndex);
    for(int i=0; i < this->_itemIndex; i++ ){
        items[i]->draw();
    }
    Serial.print("_itemtindex  out = ");Serial.println(this->_itemIndex);
}

void Page::contains(int16_t x, int16_t y){
    Serial.println("*************** PAGE::CONTIANS********************");
    Serial.print("_itemtindex = ");Serial.println(this->_itemIndex);
    Serial.print("x = ");Serial.println(x);
    Serial.print("y = ");Serial.println(y);
    for(int i=0; i < _itemIndex; i++ ){
        Serial.println("*************** PAGE::CONTIANS::FOR LOOP********************");
        Serial.print("checking Item:"); Serial.println(i);
        items[i]->press(x,y);
    }
    
}