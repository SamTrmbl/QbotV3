#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Qbot.h> //Ce fichier doit être dans le dossier "include"

//Manette manette;


float kP = 2; // à calibrer pour chaque robot


void setup() {
  Serial.begin(9600);
  //manette.begin();
  gyroBegin(-6.85,0.92,-4.62);
  //servoBegin();
  
}

void loop() {
  //manette.read();

  arcadeDrive(50,-kP*angle());

  

}