#ifndef _MENU_H
#define _MENU_H
#include "item.h"
#include "menuItem.h"
#include "page.h"
class Menu: public Item{
private:
    location_enum _location;
    menuItem menuitems[6];
    int _menuItemIndex;
    
public:
    Menu();
    Menu(Elegoo_GFX *display,String name, int16_t h, int16_t w, 
            int8_t textSize, 
            bool visible, bool border, 
            location_enum loc, 
            uint16_t borderColor = BLUE, 
            uint16_t fillColor = WHITE,
            uint16_t textColor = BLUE );
    ~Menu();
    virtual void draw() override;
    void addMenuItem(menuItem menuitem);
    void drawMenuItems();
     
  
    void print(String p);
};





#endif 
