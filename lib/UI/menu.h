#ifndef _MENU_H
#define _MENU_H
#include "item.h"
#include "menuItem.h"
#include "page.h"
#include "button.h"
#include "textBox.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;
class Menu: public Item{
private:
    int _location;
    menuItem *_menuitems[6];
    int _menuItemIndex = 0;
public:
    Menu(){};
    Menu(Elegoo_GFX*, String, int16_t, int16_t, int8_t, bool, bool, int, 
        uint16_t borderColor=BLUE, uint16_t fillColor=WHITE, uint16_t textColor=BLUE);
    ~Menu(){};
    void draw();
    void addMenuItem(menuItem *);
    void drawMenuItems();  
    void print(String p);
    void press(int16_t x, int16_t y);
};





#endif 
