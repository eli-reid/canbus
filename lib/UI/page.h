#ifndef _PAGE_H
#define _PAGE_H
#include <stdint.h>
#include <string.h>
#include "item.h"
class Page
{
    protected:
        Item *items[20];
        int _itemIndex = 0;
    public:
        void draw();
        void addItem(Item *item);
        void contains(int16_t x, int16_t y);
};
#endif