#ifndef _TEXTBOX_H
#define _TEXTBOX_H

using namespace std;

#include <Elegoo_GFX.h>
#include <StandardCplusplus.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <string>
#include <string.h>
#include "colors_dfs.h"
#include "item.h"
class textBox : public Item
{
private:
    int test;
    list<String> lines;


public:
    textBox  (Elegoo_GFX  *display, String name, int16_t h, int16_t w, int8_t textSize, bool visible, bool border, int16_t x, int16_t y , 
        uint16_t borderColor=BLUE,   uint16_t fillColor = BLACK, uint16_t textColor = WHITE);
    textBox(/* args */);
    ~textBox();
    void update();
    void draw();
    void print(String text);

};

#endif  