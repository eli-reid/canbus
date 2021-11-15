#ifndef _PAGE_H
#define _PAGE_H
#include <stdint.h>
#include "item.h"
class Page
{
protected:
    Item *items[20];
    int _itemIndex;
public:

    Page(/* args */);
    ~Page();
   
    void draw();
    void addItem(Item *item);
    void removeItem(int index);
    void contains(int16_t x, int16_t y);

};




#endif