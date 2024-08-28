#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>
// class object in class (if they communicate through protocol)
MPU6050 mpu6050(Wire);
Servo myservo;
 void setup(){
   Serial.begin(9600);
  // to begin I2c bus serial communication
   Wire.begin();
   mpu6050.begin();
  // to  calibrate the gyroscope offsets to minimize errors due to sensor drift. It calculates and stores the zero-point offsets for the gyroscope.

   mpu6050.calcGyroOffsets();
  //  line attaches the `myservo` object to digital pin 3 on the Arduino. This means that the servo motor will be controlled through pin 3.
  myservo.attach(3);
 }
 void loop(){
  // to get most updated angle and acceleration readings 
   mpu6050.update();
   int angleX = mpu6050.getAngleX();
   angleX =map(angleX,85,-85,0,180);
   myservo.write(angleX);
   delay(10);
 }
