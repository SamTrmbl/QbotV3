#include <Arduino.h>
#include <PS2X_lib.h>
#include <Manette.h>

Manette::Manette() : _ps2x() {
}


void Manette::begin(){
    _ps2x.config_gamepad(50, 51, 53, 52, false, false);

}

int Manette::getLY(){
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(PSS_LY), 255,0,-100,100);
}