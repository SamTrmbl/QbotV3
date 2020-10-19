#ifndef MANETTE_H
#define MANETTE_H
#include <Arduino.h>
#include <PS2X_lib.h>


class Manette{

    public:
    Manette();
    void begin();//À mettre dans le setup
    void read();//À mettre dans le loop, patch pour que les toggle fonctionnent

    int axis(byte axe);
    int LY();
    int LX();
    int RY();
    int RX();

    bool bouton (int bouton, bool debouncer);
    bool triangle();
    bool triangleToggle();
    bool square();
    bool squareToggle();
    bool circle();
    bool circleToggle();
    bool cross();
    bool crossToggle();
    bool dPadUp();
    bool dPadUpToggle();
    bool dPadRight();
    bool dPadRightToggle();
    bool dPadDown();
    bool dPadDownToggle();
    bool dPadLeft();
    bool dPadLeftToggle();
    bool start();
    bool startToggle();
    bool select();
    bool selectToggle();
    bool L2();
    bool L2Toggle();
    bool R2();
    bool R2Toggle();
    bool L1();
    bool L1Toggle();
    bool R1();
    bool R1Toggle();
    bool L3();/////TODO Renommer R3 et L3 pour que ça soit plus clair que ce sont les boutons des jjoysticks
    bool L3Toggle();
    bool R3();
    bool R3Toggle();



    
    private:
    PS2X _ps2x;
    byte _axe;
    int _bouton;
    bool _debouncer;

        
};


#endif
