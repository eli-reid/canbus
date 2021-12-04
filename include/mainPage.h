#ifndef _MAINPAGE_H
#define _MAINPAGE_H

#include <Elegoo_GFX.h>
#include "page.h"
#include "statusBar.h"
#include "menu.h"
#include "item.h"
#include "textBox.h"

void f(){
        Serial.println("func works");
}

class mainPage: public Page
{
public:
        Menu menu;
        statusBar sb;
        textBox tb;
        

        //textbox 
        void init(Elegoo_GFX* screen);
        ~mainPage();
};

void mainPage::init(Elegoo_GFX *screen)
{        
        _itemIndex = 0;      
        sb = statusBar(screen,"StatusBar",30, screen->width(),2,true,true,BOTTOM,GREEN,BLACK);
        menu =  Menu(screen,"MenuBar",30,screen->width(),1,true,true,TOP);
        tb = textBox(screen,"Textbox",200,screen->width(),1,true,true,0,32);
        sb.onPress = f;    

        addItem(&menu);
        addItem(&sb); 
        addItem(&tb);
        
}

mainPage::~mainPage()
{
}


#endif