#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);
Servo myservo;
 void setup(){
   Serial.begin(9600);
   Wire.begin();
   mpu6050.begin();
   mpu6050.calcGyroOffsets();
   myservo.attach(3);
 }
 void loop(){
   mpu6050.update();
   int angleX = mpu6050.getAngleX();
   angleX =map(angleX,85,-85,0,180);
   myservo.write(angleX);
   delay(10);
 }