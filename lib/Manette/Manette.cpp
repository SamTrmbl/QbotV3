#include <Arduino.h>
#include <PS2X_lib.h>
#include <Manette.h>

Manette::Manette() : _ps2x() {

}

//Doit être placé au début du SETUP
//initialise la manette aux bons ports
void Manette::begin(){
    _ps2x.config_gamepad(50, 51, 53, 52, false, false);

}

//Doit être placé au début du LOOP, 
//Lecture du gamepad à chaque itération de la boucle
void Manette::read(){
    _ps2x.read_gamepad();
}

//Fonction générique pour obtenir les valeurs d'axe de joystick
int Manette::axis(byte axe){
    _axe = axe;
    _ps2x.read_gamepad();
    delay(10);
    return map(_ps2x.Analog(axe),0, 255,-100,100); //Afin que +100 soit à droite, -100 à gauche
    //Il faut inverser la sortie pour les axes LY et RY afin que +100 vers le haut et-100 vers le bas


}

int Manette::LY(){
    return -axis(PSS_LY);//Afin que +100 soit à droite, -100 à gauche
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


//Fonction générique pour créer les boutons
bool Manette::bouton(int bouton, bool uneFois){
    _bouton = bouton;
    _uneFois = uneFois;
    if (_uneFois)
    {
        return _ps2x.ButtonPressed(_bouton);
    }
    else
    {
         return _ps2x.Button(_bouton);
    }
}



//Créeation de tous les boutons, en version APPUYER et en version UneFois
bool Manette::triangle(){return bouton(PSB_TRIANGLE,false);}
bool Manette::triangleUneFois(){return bouton(PSB_TRIANGLE,true);}
bool Manette::square(){return bouton(PSB_SQUARE,false);}
bool Manette::squareUneFois(){return bouton(PSB_SQUARE,true);}
bool Manette::circle(){return bouton(PSB_CIRCLE,false);}
bool Manette::circleUneFois(){return bouton(PSB_CIRCLE,true);}
bool Manette::cross(){return bouton(PSB_CROSS,false);}
bool Manette::crossUneFois(){return bouton(PSB_CROSS,true);}
bool Manette::dPadUp(){return bouton(PSB_PAD_UP,false);}
bool Manette::dPadUpUneFois(){return bouton(PSB_PAD_UP,true);}
bool Manette::dPadRight(){return bouton(PSB_PAD_RIGHT,false);}
bool Manette::dPadRightUneFois(){return bouton(PSB_PAD_RIGHT,true);}
bool Manette::dPadDown(){return bouton(PSB_PAD_DOWN,false);}
bool Manette::dPadDownUneFois(){return bouton(PSB_PAD_DOWN,true);}
bool Manette::dPadLeft(){return bouton(PSB_PAD_LEFT,false);}
bool Manette::dPadLeftUneFois(){return bouton(PSB_PAD_LEFT,true);}
bool Manette::start(){return bouton(PSB_START,false);}
bool Manette::startUneFois(){return bouton(PSB_START,true);}
bool Manette::select(){return bouton(PSB_SELECT,false);}
bool Manette::selectUneFois(){return bouton(PSB_SELECT,true);}
bool Manette::L2(){return bouton(PSB_L2,false);}
bool Manette::L2UneFois(){return bouton(PSB_L2,true);}
bool Manette::R2(){return bouton(PSB_R2,false);}
bool Manette::R2UneFois(){return bouton(PSB_R2,true);}
bool Manette::L1(){return bouton(PSB_L1,false);}
bool Manette::L1UneFois(){return bouton(PSB_L1,true);}
bool Manette::R1(){return bouton(PSB_R1,false);}
bool Manette::R1UneFois(){return bouton(PSB_R1,true);}
bool Manette::LJoystickButton(){return bouton(PSB_L3,false);}
bool Manette::LJoystickButtonUneFois(){return bouton(PSB_L3,true);}
bool Manette::RJoystickButton(){return bouton(PSB_R3,false);}
bool Manette::RJoystickButtonUneFois(){return bouton(PSB_R3,true);}

