#include <Arduino.h>
#include <PS2X_lib.h>
#include <Manette.h>

Manette::Manette() : _ps2x() {
}


void Manette::begin(){
    _ps2x.config_gamepad(50, 51, 53, 52, false, false);//initialise la manette aux bons ports

}

int Manette::axis(byte axe){//Cette fonction est callée explicitement pour chaque axe ci-bas
    _axe = axe;
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(axe),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
    //Il faut inverser la sortie pour les axes LY et RY afin que +100 vers le haut et-100 vers le bas


}

int Manette::LY(){
    return -axis(PSS_LY);
}
// à refaire comme LY ATTENTION AU SIGNE !
int Manette::LX(){
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(PSS_LX),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
}

int Manette::RY(){
    _ps2x.read_gamepad(); 
    delay(10); 
    return map(_ps2x.Analog(PSS_RY), 255,0,-100,100); //Afin que +100 soit en haut, -100 en bas
}

int Manette::RX(){
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(PSS_RX),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
}


bool Manette::bouton(int bouton, bool debouncer){
    _bouton = bouton;
    _debouncer = debouncer;
    _ps2x.read_gamepad();
    delay(10);
    if (_debouncer)
    {
        return _ps2x.ButtonPressed(_bouton);
    }
    else
    {
         return _ps2x.Button(_bouton);
    }
}

bool Manette::triangle(){return bouton(PSB_TRIANGLE,false);}
bool Manette::triangleD(){return bouton(PSB_TRIANGLE,true);}

//À faire pour tous les boutons, en version standard et debounce