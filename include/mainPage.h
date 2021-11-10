#ifndef _MAINPAGE_H
#define _MAINPAGE_H

#include <Elegoo_GFX.h>
#include "page.h"
#include "statusBar.h"
#include "menu.h"
#include "item.h"


class mainPage: public Page
{
private:

public:
        statusBar statbar;
        Menu menu;

        mainPage(Elegoo_GFX *screen);
        ~mainPage();
};

mainPage::mainPage(Elegoo_GFX *screen)
{
        statbar = statusBar(screen,20, screen->width(),1,true,true,BOTTOM);
        menu =  Menu(screen,30,screen->width(),2,true,true,TOP);
        addItem(&menu);
        addItem(&statbar);
}

mainPage::~mainPage()
{
}


#endif