#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

/////GYRO

MPU6050 mpu(Wire);
void gyroBegin(float offsetX, float offsetY, float offsetZ){
  Wire.begin();
  mpu.begin();
  if (offsetX == 0 and offsetY == 0 and offsetZ ==0){
    mpu.calcGyroOffsets(true);
  }
  else{
    mpu.setGyroOffsets(offsetX, offsetY, offsetZ);
  }
  
}

float resetAngle=0;

float rawAngle(){
  mpu.update();
  delay(50);
  return mpu.getGyroAngleZ();
}

float angle(){
  return rawAngle()-resetAngle;//resetAngle se met à jour quand gyroReset est callé
}

void gyroReset(){
  //Mettre à jour le resetAngle afin de ramener la valeur à 0
  resetAngle=rawAngle();
}
