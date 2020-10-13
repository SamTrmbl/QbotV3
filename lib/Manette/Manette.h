#ifndef MANETTE_H
#define MANETTE_H
#include <Arduino.h>
#include <PS2X_lib.h>


class Manette{

    public:
    Manette();
    void begin();

    int axis(byte axe);
    int LY();
    int LX();
    int RY();
    int RX();

    bool bouton (int bouton, bool debouncer);
    bool triangle();
    bool triangleD();

    private:
    PS2X _ps2x;
    byte _axe;
    int _bouton;
    bool _debouncer;
        
};


#endif
