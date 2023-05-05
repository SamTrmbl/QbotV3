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
V3.2 : Gestion automatique des 2 modèles de shields, renommer
       les fonctions Toggle en UneFois pour mieux refléter leur
       fonction. Avril 2023
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

    bool bouton (int bouton, bool uneFois);
    bool triangle();
    bool triangleUneFois();
    bool square();
    bool squareUneFois();
    bool circle();
    bool circleUneFois();
    bool cross();
    bool crossUneFois();
    bool dPadUp();
    bool dPadUpUneFois();
    bool dPadRight();
    bool dPadRightUneFois();
    bool dPadDown();
    bool dPadDownUneFois();
    bool dPadLeft();
    bool dPadLeftUneFois();
    bool start();
    bool startUneFois();
    bool select();
    bool selectUneFois();
    bool L2();
    bool L2UneFois();
    bool R2();
    bool R2UneFois();
    bool L1();
    bool L1UneFois();
    bool R1();
    bool R1UneFois();
    bool LJoystickButton();
    bool LJoystickButtonUneFois();
    bool RJoystickButton();
    bool RJoystickButtonUneFois();



    
    private:
    PS2X _ps2x;
    byte _axe;
    int _bouton;
    bool _uneFois;

        
};


#endif
