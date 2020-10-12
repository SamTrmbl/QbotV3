#include <Arduino.h>
#include <PS2X_lib.h>
#include <Manette.h>

Manette::Manette() : _ps2x() {
}


void Manette::begin(){
    _ps2x.config_gamepad(50, 51, 53, 52, false, false);//initialise la manette aux bons ports

}

int Manette::getLY(){
    _ps2x.read_gamepad(); //obtient l'info de la manette
    delay(10); //éviter un bug se synchronisation
    return map(_ps2x.Analog(PSS_LY), 255,0,-100,100); //Afin que +100 soit en haut, -100 en bas
}

int Manette::getLX(){
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(PSS_LX),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
}

int Manette::getRY(){
    _ps2x.read_gamepad(); 
    delay(10); 
    return map(_ps2x.Analog(PSS_RY), 255,0,-100,100); //Afin que +100 soit en haut, -100 en bas
}

int Manette::getRX(){
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(PSS_RX),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
}