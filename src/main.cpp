#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Moteur.h>//La librairie Encoder de Paul Stoffegen v 1.4.1 doit être installée dans Platformio
#include <PS2X_lib.h>
Manette manette;
bool toggle = false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
manette.begin();

}

void loop() {

  manette.read();

Serial.println(distanceAvG());

  if (manette.squareToggle()){
    toggle = !toggle;
  }
  
  if (toggle)
  {
    simpleDrive(50);
  }
  else{
    stop();
  }

  if(manette.triangleToggle()){
    resetEncoder();
  }

}