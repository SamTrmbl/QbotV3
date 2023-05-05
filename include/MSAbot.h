#include <Arduino.h>
#include <Servo.h>


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

}


///////Définition des moteurs de chaque roues

void vitesseGauche(int vitesse){
  vitesseRoueLowLevel(2,4,3,vitesse);
}

void vitesseDroite(int vitesse){
  vitesseRoueLowLevel(7,8,5,vitesse);
}



////////////Drive modes

void stop(){
  vitesseDroite(0);
  vitesseGauche(0);

} 

//Tous les drives prennents de valeurs de -100 à +100
void simpleDrive(int vitesse){//Avancer-reculer. + = en avant
  
  vitesseGauche(vitesse);
  vitesseDroite(vitesse);

}

void arcadeDrive(int vx, int vz){//Avancer et tourner. +x = avant, +z = tourne horaire
 
 int vg = vx+vz;
 int vd = vx-vz;


 vitesseGauche(vg);
 vitesseDroite(vd);

}

/////SERVO

Servo servomoteur; //Servo principal, sur la pin 44


void servoBegin(){//À mettre dans le setup pour initialiser les servos
servomoteur.attach(9);

}

//Fonction générique donnant un angle à un servo
void angleServo(Servo servomoteur, int angle){
  angle = constrain(angle,10,170);//Servo limité de 10 à 170 degrés
  servomoteur.write(angle);
}

void servo(int angle){
  return angleServo(servomoteur, angle);
}

