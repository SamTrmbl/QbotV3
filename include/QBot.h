#include <Arduino.h>
/*Les librairies suivantes n'ont pas à être installée
Elles sont appellées dans le platformio.ini*/
#include <Encoder.h>
#include <Ultrasonic.h>



/*Ultrasonic capteurUltrason(1,1); //SAM Trouver les pins, valider

int ultrason(){
  return  capteurUltrason.read();
}

bool antenne(){//SAM trouver la pin du sensor, s'assurer que cliquer = False
  return digitalRead(6);
}*/

///////Définition des moteurs de chaque roues
void vitesseRoueLowLevel(int pinA, int pinB, int pinPWM, float vitesse){
  int _vitesse = vitesse;
  _vitesse = constrain(_vitesse,-100,100);// accepte des valeurs de -100 à 100

  _vitesse = map(_vitesse,-100,100,-255,255); //transfert ces valeurs sur la bonne plage PWM
  if(abs(_vitesse)<20){//dead band
    _vitesse=0;
  }
  bool direction = _vitesse >= 0; //avancer = True
  digitalWrite(pinA,!direction); //Pour avancer, la pin A est à 0 et la pin B est à 1
  digitalWrite(pinB,direction);
  analogWrite(pinPWM, abs(_vitesse));
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

void stop(){
  vitesseAvD(0);
  vitesseAvG(0);
  vitesseArD(0);
  vitesseArG(0);
} 
//Tous les drives prennents de valeurs de -100 à +100
void simpleDrive(int vitesse){//Avancer-reculer. + = en avant
  
  vitesseAvG(vitesse);
  vitesseAvD(vitesse);
  vitesseArG(vitesse);
  vitesseArD(vitesse);
}

void arcadeDrive(int vx, int vz){//Avancer et tourner. +x = avant, +z = tourne horaire
 
 int vg = vx+vz;
 int vd = vx-vz;


 vitesseAvG(vg);
 vitesseAvD(vd);
 vitesseArG(vg);
 vitesseArD(vd);
}

void mecanumDrive(int vx, int vy, int vz){//+x = en avant, +y = droite, +z = horaire

 int vAvG = vx+vz+vy;
 int vAvD = vx-vz-vy;
 int vArG = vx+vz-vy;
 int vArD = vx-vz+vy;

 vitesseAvG(vAvG);
 vitesseAvD(vAvD);
 vitesseArG(vArG);
 vitesseArD(vArD);
}


/////Encodeurs

Encoder encodeurAvG(18,31);
Encoder encodeurAvD(19,38);
Encoder encodeurArG(3,49);
Encoder encodeurArD(2,A1);


//Fonction générique
long distanceLowLevel(Encoder encodeur){
  
    //long pour éviter l'overflow
  return encodeur.read()/1000;//diviser par 1000 car c'est environ un tour de shaft
}

void resetEncoder(){
  encodeurAvG.write(0);
  encodeurAvD.write(0);
  encodeurArG.write(0);
  encodeurArD.write(0);
}

long distanceAvG(){
  return -distanceLowLevel(encodeurAvG);
}

long distanceAvD(){
  return distanceLowLevel(encodeurAvD);
}

long distanceArG(){
  return -distanceLowLevel(encodeurArG);
}

long distanceArD(){
  return distanceLowLevel(encodeurArD);
}

long distance(){
  return (distanceAvD() + distanceAvG() + distanceArG() + distanceArD())/4;
}

long distanceDroite(){
  return(distanceAvD() + distanceArD())/2;
}

long distanceGauche(){
  return (distanceAvG() + distanceArG())/2;
}


