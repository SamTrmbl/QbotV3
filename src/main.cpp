#include <Arduino.h>
#include <Manette.h>//Le dossier (pas le zip) de la librairie P2X_lib doit être dans le dossier "lib"
#include <Moteur.h>//La librairie Encoder de Paul Stoffegen v 1.4.1 doit être installée dans Platformio
#include <Encoder.h>

Manette manette;
Encoder enc(18,31);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
manette.begin();


}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(enc.read());
  /*Serial.print(digitalRead(18));
  Serial.print(",");
  Serial.print(digitalRead(31));
  Serial.print(",");
  Serial.print(digitalRead(19));
  Serial.print(",");
  Serial.print(digitalRead(38));
  Serial.print(",");
  Serial.print(digitalRead(3));
  Serial.print(",");
  Serial.print(digitalRead(49));
  Serial.print(",");
  Serial.print(digitalRead(2));
  Serial.print(",");
  Serial.println(digitalRead(A1));*/
  
  


}