#include "Page.h"

void Page::addItem(Item *item){
    items[this->_itemIndex] = item;
    item->setIndex(this->_itemIndex);
    this->_itemIndex++;
}

void Page::draw(){
    for(int i=0; i < this->_itemIndex; i++ ){
        items[i]->draw();
    }
}

void Page::contains(int16_t x, int16_t y){
    for(int i=0; i < _itemIndex; i++ ){
        items[i]->press(x,y);
        if(items[i]->isPressed())// insure only one item is touched
            break;
    }
    
}
void Page::replaceItem(int itemIndex, Item *item){
    items[itemIndex] = item;
    item->setIndex(itemIndex);
}