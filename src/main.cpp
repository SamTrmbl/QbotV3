#include <Arduino.h>
#include <Manette.h>


int vitesse;
bool direction;

void vitesseRoueLowLevel(int pinA, int pinB, int pinPWM, float vitesse){
  //TODO ajouter une deadband (voir WPILIB)
  vitesse = constrain(vitesse,-100,100);// accepte des valeurs de -100 à 100
  vitesse = map(vitesse,-100,100,-255,255); //transfert ces valeurs sur la bonne plage PWM
  bool direction = vitesse >= 0; //avancer = True
  digitalWrite(pinA,!direction); //Pour avancer, la pin A est à 0 et la pin B est à 1
  digitalWrite(pinB,direction);
  analogWrite(pinPWM, abs(vitesse));
}

void vitesseAvG(float vitesse){
  vitesseRoueLowLevel(34,35,12,vitesse);
}

void vitesseAvD(float vitesse){
  vitesseRoueLowLevel(36,37,8,vitesse);//inverse les pins A et B car le moteur de droite doit tourner à l'envers
}

void vitesseArG(float vitesse){
  vitesseRoueLowLevel(43,42,9,vitesse);
}

void vitesseArD(float vitesse){
  vitesseRoueLowLevel(A5,A4,5,vitesse);//inverse les pins A et B car le moteur de droite tourne à l'envers
}

void simpleDrive(float vitesse){
  
  vitesseAvG(vitesse);
  vitesseAvD(vitesse);
  vitesseArG(vitesse);
  vitesseArD(vitesse);
}

Manette manette;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
manette.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(manette.getLX());
  simpleDrive(manette.getRY());

}