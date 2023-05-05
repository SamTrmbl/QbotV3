#include <Wire.h> //Librairie permettant la communication I2C
#include <MPU6050_tockn.h> //Libraire externe de gyro.

/////GYRO

MPU6050 mpu(Wire); //Créer l'objet gyroscope

void gyroBegin(float offsetX, float offsetY, float offsetZ){//À mettre dans le setup
  Wire.begin();
  mpu.begin();
  if (offsetX == 0 and offsetY == 0 and offsetZ ==0){//Si gyroBegin(0,0,0), on calibre.
    mpu.calcGyroOffsets(true);
  }
  else{
    mpu.setGyroOffsets(offsetX, offsetY, offsetZ);//Pas de calibration si on inscrit des valeurs
  }
  
}

float resetAngle=0;

float rawAngle(){//Obtenir l'angle du gyro, sans calcul
  mpu.update();
  delay(50);
  return mpu.getGyroAngleZ();
}

float angle(){
  return rawAngle()-resetAngle;//resetAngle se met à jour quand gyroReset est callé
}

void gyroReset(){
  //Mettre à jour le resetAngle afin de ramener la valeur de l'angle à 0
  resetAngle=rawAngle();
}
