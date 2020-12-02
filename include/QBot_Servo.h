#include <Servo.h>
#include <Arduino.h>
////TODO SAM : tester et commenter
/////SERVO

Servo servomoteur; //Servo principal, sur la pin 44
Servo servomoteur2;//servo extra
Servo servomoteur3;//servo extra

void servoBegin(){//À mettre dans le setup pour initialiser les servos
servomoteur.attach(44);
servomoteur2.attach(45);
servomoteur3.attach(46);
}

//Fonction générique donnant un angle à un servo
void angleServo(Servo servomoteur, int angle){
  angle = constrain(angle,10,170);//Servo limité de 10 à 170 degrés
  servomoteur.write(angle);
}

void servo(int angle){
  return angleServo(servomoteur, angle);
}

void servo2(int angle){
  return angleServo(servomoteur2, angle);
}

void servo3(int angle){
  return angleServo(servomoteur3, angle);
}