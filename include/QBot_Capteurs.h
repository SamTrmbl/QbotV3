#include <Arduino.h>
#include <Ultrasonic.h>

/////CAPTEURS DIVERS

Ultrasonic capteurUltrason(24,22); //pins dans le même sens que sur le capteur

int ultrason(){
  return  capteurUltrason.read();
}

bool limitSwitch(){//branchée sur senseur, cliquée = False
  return digitalRead(39);
}