#include <Arduino.h>

/////MOTEURS


//Fonction de base pour controler la direction et la vitesse d'une roue.
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

  //Fix automatique pour régler la différence entre les deux modèles de shield
  if (pinPWM == 9){
    //Si on demande d'envoyer une information à la pin 9, on envoit la même à la pin 6
    //Donc les deux modèles de shields vont fonctionner
    analogWrite(6, abs(_vitesse));
  }
}


///////Définition des moteurs de chaque roues

void vitesseAvG(int vitesse){
  vitesseRoueLowLevel(34,35,12,vitesse);
}

void vitesseAvD(int vitesse){
  vitesseRoueLowLevel(36,37,8,vitesse);//inverse les pins A et B car le moteur de droite doit tourner à l'envers
}

void vitesseArG(int vitesse){
  /*Les shields avec un point rouge utilise la pin 6 au lieu de 9.
  La fonction distanceLowLevel gère automatiquement cette différence
  en envoyant l'information simultanément aux deux pins*/
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