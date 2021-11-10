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
    items[_itemIndex++] = item;
    item->setIndex(_itemIndex);
}

void Page::removeItem(int index){
    
}

void Page::draw(){
    delay(100);
    char s[5];
    for(int i=0; i < _itemIndex; i++ ){
        items[i]->draw();
        Serial.println(itoa(i,s,0));
    }


}

void Page::contains(int16_t x, int16_t y){

    for(int i=0; i < _itemIndex; i++ ){
        if(items[i]->contains(x,y))
            items[i]->press(true);
        else
            items[i]->press(false);
    }
}