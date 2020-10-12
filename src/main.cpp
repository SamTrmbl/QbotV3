#include <Arduino.h>
#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Moteur.h>//La librairie Encoder de Paul Stoffegen v 1.4.1 doit être installée dans Platformio


Manette manette;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//manette.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getEncodeurAvG());
  //simpleDrive(manette.getLY());
  

}