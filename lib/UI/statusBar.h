#ifndef  _STATUSBAR_H
#define  _STATUSBAR_H
#include "item.h"
using namespace std;
class statusBar: public Item
{ 
    private:
        int _location;
        bool _hasStatus = false;
        String _status;

     public:
        statusBar(){};
        statusBar(Elegoo_GFX *display, String name, int16_t h, int16_t w, 
            int8_t textSize,bool visible, bool border, int location=BOTTOM, 
            uint16_t borderColor=BLUE, uint16_t fillColor=WHITE, uint16_t textColor=BLUE);
        ~statusBar(){};
        void fill() override;
        void fill(int16_t color) override;
        void printStatus();
        void printStatus(String status);
        void setStatus(String status);
        void clear();
};

#endif