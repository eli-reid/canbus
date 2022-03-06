#ifndef _MAINPAGE_H
#define _MAINPAGE_H
#define SOFTWARE_SPI
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
        Menu mainMenu, *currentMenu, Menu2;
        statusBar statusbar;
        textBox textbox;
        menuItem canConnectMenuItem,item1,item2;
        void init(Elegoo_GFX* screen);
        void changeMenu(Menu *m);
};

void mainPage::init(Elegoo_GFX *screen)
{        
        _itemIndex = 0;  
        currentMenu = &mainMenu;    
        textbox = textBox(screen,"Textbox",250,screen->width(),1,true,true,0,32);
        statusbar = statusBar(screen,"StatusBar",30, screen->width(),1,true,true,BOTTOM,GREEN,BLACK);
        
        mainMenu =  Menu(screen,"MenuBar",30,screen->width(),1,true,true,TOP);
        canConnectMenuItem = menuItem(screen,0,70,"Connect CAN");
        mainMenu.addMenuItem(&canConnectMenuItem);

        Menu2 =  Menu(screen,"MenuBar",30,screen->width(),1,true,true,TOP);
        item1 = menuItem(screen,0,70,"Disconnect");
        item2 = menuItem(screen,1,70,"Dtest");
        Menu2.addMenuItem(&item1);
        Menu2.addMenuItem(&item2);

        addItem(&mainMenu);
        addItem(&statusbar); 
        addItem(&textbox);
}

void mainPage::changeMenu(Menu *m){
        replaceItem(currentMenu->getIndex(), m);
        currentMenu = m;
        m->fill(BLACK);
        m->draw();
}

#endif