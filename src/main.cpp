#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <MSAbot.h> //Ce fichier doit être dans le dossier "include"

Manette manette;

void conduire();

void setup() {
  Serial.begin(9600);
  manette.begin();
  servoBegin();
  
}

void loop() {
  manette.read();
  conduire();

}


//La fonction qui permet de conduire le robot
void conduire(){
    arcadeDrive(manette.LY(), manette.RX());
}