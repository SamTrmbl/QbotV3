#include <Arduino.h>
#include <PS2X_lib.h>
#include <Manette.h>

Manette::Manette() : _ps2x() {
}


void Manette::begin(){
    _ps2x.config_gamepad(50, 51, 53, 52, false, false);//initialise la manette aux bons ports

}

void Manette::read(){//Doit être placé au début du loop, remplace la lecture du gamepad dans la fonction bouton
    _ps2x.read_gamepad();
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

int Manette::LX(){
    return axis(PSS_LX); //Afin que +100 soit à droite, -100 à gauche
}

int Manette::RY(){
    return -axis(PSS_RY); //Afin que +100 soit en haut, -100 en bas
}
    
int Manette::RX(){
    return axis(PSS_RX); //Afin que +100 soit à droite, -100 à gauche
}

bool Manette::bouton(int bouton, bool debouncer){
    _bouton = bouton;
    _debouncer = debouncer;
    //_ps2x.read_gamepad(); //Ceci fonctionne bien pour les fonctions de base, mais pas le toggle.
    //delay(10);
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
bool Manette::triangleToggle(){return bouton(PSB_TRIANGLE,true);}
bool Manette::square(){return bouton(PSB_SQUARE,false);}
bool Manette::squareToggle(){return bouton(PSB_SQUARE,true);}
bool Manette::circle(){return bouton(PSB_CIRCLE,false);}
bool Manette::circleToggle(){return bouton(PSB_CIRCLE,true);}
bool Manette::cross(){return bouton(PSB_CROSS,false);}
bool Manette::crossToggle(){return bouton(PSB_CROSS,true);}
bool Manette::dPadUp(){return bouton(PSB_PAD_UP,false);}
bool Manette::dPadUpToggle(){return bouton(PSB_PAD_UP,true);}
bool Manette::dPadRight(){return bouton(PSB_PAD_RIGHT,false);}
bool Manette::dPadRightToggle(){return bouton(PSB_PAD_RIGHT,true);}
bool Manette::dPadDown(){return bouton(PSB_PAD_DOWN,false);}
bool Manette::dPadDownToggle(){return bouton(PSB_PAD_DOWN,true);}
bool Manette::dPadLeft(){return bouton(PSB_PAD_LEFT,false);}
bool Manette::dPadLeftToggle(){return bouton(PSB_PAD_LEFT,true);}
bool Manette::start(){return bouton(PSB_START,false);}
bool Manette::startToggle(){return bouton(PSB_START,true);}
bool Manette::select(){return bouton(PSB_SELECT,false);}
bool Manette::selectToggle(){return bouton(PSB_SELECT,true);}
bool Manette::L2(){return bouton(PSB_L2,false);}
bool Manette::L2Toggle(){return bouton(PSB_L2,true);}
bool Manette::R2(){return bouton(PSB_R2,false);}
bool Manette::R2Toggle(){return bouton(PSB_R2,true);}
bool Manette::L1(){return bouton(PSB_L1,false);}
bool Manette::L1Toggle(){return bouton(PSB_L1,true);}
bool Manette::R1(){return bouton(PSB_R1,false);}
bool Manette::R1Toggle(){return bouton(PSB_R1,true);}
bool Manette::LJoystickButton(){return bouton(PSB_L3,false);}
bool Manette::LJoystickButtonToggle(){return bouton(PSB_L3,true);}
bool Manette::RJoystickButton(){return bouton(PSB_R3,false);}
bool Manette::RJoystickButtonToggle(){return bouton(PSB_R3,true);}

