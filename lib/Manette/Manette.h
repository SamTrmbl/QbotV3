#ifndef MANETTE_H
#define MANETTE_H
#include <Arduino.h>
#include <PS2X_lib.h>


class Manette{

    public:
    Manette();
    void begin();
    int getLY();

    private:
    PS2X _ps2x;
        
};


#endif
