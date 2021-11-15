#ifndef _MAINPAGE_H
#define _MAINPAGE_H

#include <Elegoo_GFX.h>
#include "page.h"
#include "statusBar.h"
#include "menu.h"
#include "item.h"


class mainPage: public Page
{
public:
        Menu menu;
        statusBar sb;
        void init(Elegoo_GFX* screen);
        ~mainPage();
};

void mainPage::init(Elegoo_GFX *screen)
{        
        _itemIndex = 0;      
        sb=statusBar(screen,"StatusBar",20, screen->width(),1,true,true,BOTTOM);
        menu =  Menu(screen,"MenuBar",30,screen->width(),2,true,true,TOP);


        addItem(&menu);
        addItem(&sb);
        
}

mainPage::~mainPage()
{
}


#endif