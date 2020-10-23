#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Qbot.h>

Manette manette;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  manette.begin();

}

void loop() {

  manette.read();




  arcadeDrive(manette.LY(), manette.RX());
  Serial.println(distance());
 //simpleDrive(manette.LY());

}