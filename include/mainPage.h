#ifndef _MAINPAGE_H
#define _MAINPAGE_H

#include <Elegoo_GFX.h>
#include "page.h"
#include "statusBar.h"
#include "menu.h"
#include "item.h"
#include "textBox.h"
#include "menuItem.h"

class mainPage: public Page
{
public:
        Menu menu;
        statusBar statusbar;
        textBox textbox;
        menuItem menuitem1;
        void init(Elegoo_GFX* screen);
};

void mainPage::init(Elegoo_GFX *screen)
{        
        _itemIndex = 0;      
        textbox = textBox(screen,"Textbox",250,screen->width(),1,true,true,0,32);
        statusbar = statusBar(screen,"StatusBar",30, screen->width(),1,true,true,BOTTOM,GREEN,BLACK);
        
        menu =  Menu(screen,"MenuBar",30,screen->width(),1,true,true,TOP);
        menuitem1 = menuItem(screen,0,70,"Connect CAN");
        menu.addMenuItem(&menuitem1);
     
        addItem(&menu);
        addItem(&statusbar); 
        addItem(&textbox);
}

#endif