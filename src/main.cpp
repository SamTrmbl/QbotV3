#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Qbot.h>

Manette manette;


void setup() {
  Serial.begin(9600);
  manette.begin();
  gyroBegin(-6.48,0.94,-4.7); //Mettre (0,0,0)pour calibrer, voir le moniteur série pour les valeurs
}

void loop() {
  manette.read();

  Serial.print(angle());
  Serial.print(" , ");
  Serial.println(resetAngle);
  if (manette.triangle()){
    gyroReset();
  }

}