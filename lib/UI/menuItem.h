#ifndef _MENUITEM_H
#define _MENUITEM_H
#include <stdint.h>
#include <stdbool.h>
#include "colors_dfs.h"
#include "Arduino.h"
#include "item.h"

class menuItem : public Item
{
private:
    int _index;
    String _title;
public:
    menuItem(){};
    menuItem(Elegoo_GFX * display, int index, int width, String title);
    ~menuItem(){};
    void setHeight(int16_t h);
    void setWidth(int16_t w);
    void setX(int16_t x);
    void setY(int16_t y);
    int getIndex() const;
    int16_t getWidth() const;
    int16_t getHeight() const;
    int16_t getX() const;
    int16_t getY() const;
    void draw() override;
  
};
#endif