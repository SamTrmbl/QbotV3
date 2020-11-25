#include <Arduino.h>
#include <Servo.h>

/////SERVO

Servo servomoteur;
Servo servomoteur2;
Servo servomoteur3;

void servoBegin(){
servomoteur.attach(44);
servomoteur2.attach(45);
servomoteur3.attach(46);
}

void angleServo(Servo servomoteur, int angle){
  angle = constrain(angle,10,170);
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