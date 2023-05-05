/*Cette librairie est un wrapper permettant une utilisation facile de la 
librairie PS2X_lib v1.9 (https://github.com/Lynxmotion/Arduino-PS2X) afin
de contrôler le robot mecanum de MoebiusTech à l'aide d'une manette de PS2.

Nous utilisons ce robot comme la 3e génération du projet "Qbot" du cours de
robotique de 3e secondaire de la Polyvalente de Charlesbourg. 

Cette librairie a été conçue par Vincent Lavoie, Jayson Poirier et Samuel Tremblay.
 
Contact : samuel.tremblay.2@cssps.gouv.qc.ca

Creative Commons BY-NC-SA

V3.0 : Release initial, décembre 2020.
V3.1 : Ajout de la procédure pour corriger le pinout différent 
       des shields achetés l'été précédent, décembre 2022.
*/

#ifndef MANETTE_H
#define MANETTE_H
#include <Arduino.h>
#include <PS2X_lib.h>

//Le librairie PS2X_lib doit être dans le dossier "lib" du projet

class Manette{

    public:
    Manette();
    void begin();//À mettre dans le setup
    void read();//À mettre dans le loop
    

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
    bool LJoystickButton();
    bool LJoystickButtonToggle();
    bool RJoystickButton();
    bool RJoystickButtonToggle();



    
    private:
    PS2X _ps2x;
    byte _axe;
    int _bouton;
    bool _debouncer;

        
};


#endif
