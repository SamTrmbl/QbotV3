#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Qbot.h>



//Manette manette;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

 // manette.begin();
  gyroBegin(-6.48,0.94,-4.7);

}

void loop() {
  //manette.read();

  //mecanumDrive(manette.LY(), manette.LX(), manette.RX());

  Serial.println(angle());
  arcadeDrive(0,90-angle());
  



}