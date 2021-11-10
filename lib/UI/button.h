#ifndef _BUTTON_H
#define _BUTTON_H
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07F
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#include <string.h>
#include <Elegoo_GFX.h>

class button
{

    private:
        int16_t _w, _h, _x, _y, _fillColor, _borderColor, _textColor;
        int8_t _textSize;
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

        void drawButton();

};





#endif