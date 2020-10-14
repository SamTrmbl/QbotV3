#include <Arduino.h>
#include <Encoder.h> //Installer la librairie Encoder de Paul Stoffregen v1.4.1 dans platformio


///////Définition des moteurs de chaque roues
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

void vitesseAvG(int vitesse){
  vitesseRoueLowLevel(34,35,12,vitesse);
}

void vitesseAvD(int vitesse){
  vitesseRoueLowLevel(36,37,8,vitesse);//inverse les pins A et B car le moteur de droite doit tourner à l'envers
}

void vitesseArG(int vitesse){
  vitesseRoueLowLevel(43,42,9,vitesse);
}

void vitesseArD(int vitesse){
  vitesseRoueLowLevel(A5,A4,5,vitesse);//inverse les pins A et B car le moteur de droite tourne à l'envers
}

////////////Drive modes

/////Faire un STOP

void simpleDrive(int vitesse){
  
  vitesseAvG(vitesse);
  vitesseAvD(vitesse);
  vitesseArG(vitesse);
  vitesseArD(vitesse);
}

void arcadeDrive(int vx, int vz){
 //refaire algorithme
 int vg = vx+vz;
 int vd = vx-vz;

 vitesseAvG(vg);
 vitesseAvD(vd);
 vitesseArG(vg);
 vitesseArD(vd);
}


/////Encodeurs

Encoder encodeurAvG(18,31);

int getEncodeurAvG(){
  return encodeurAvG.read();//ne fonctionne pas à valider
}