#ifndef _BUTTON_H
#define _BUTTON_H
#include <string.h>
#include <Elegoo_GFX.h>
#include "item.h"
#include "colors_dfs.h"
class button : public Item
{

    private:
        bool _visible, _init;
        char* _label;
        Elegoo_GFX  *_display;


    public:
        button(Elegoo_GFX  *display, int16_t x, int16_t y, int16_t h, int16_t w,
                    char *label, int8_t textSize, bool visible, uint16_t borderColor=BLUE, 
                    uint16_t fillColor = WHITE, uint16_t textColor = BLUE);
        button();

        
        ~button();
        void init(Elegoo_GFX  *display, int16_t x, int16_t y, int16_t h, int16_t w,
                    char *label, int8_t textSize, bool visible, uint16_t borderColor=BLUE, 
                    uint16_t fillColor = WHITE, uint16_t textColor = BLUE);

};





#endif