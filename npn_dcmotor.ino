// initialize potentiometer pin as 0 and potentiometer & motorspeed value as 0 
int potPin=0; 
int motorPin= 5;
int potVal=0;
int motorSpeed=0;
 
void setup(){
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
  pinMode(potPin,INPUT);

}
void loop(){
  potVal =analogRead(A0);
  Serial.print("potvalue");
  Serial.println(potVal);
  delay(2000);
 //Initialize the motor speed and pot value before 
 // who is going to be mapped=(from which mapping take place,min value,max value,min,max)
 // analogRead has 10 bit ADC, potentiometer 0 to 1023
 // motor will run on 0 to 255 as PWM Signal controls it
 motorSpeed = map(potVal,0,1023,0,255);
  Serial.print("motorSpeed");
  Serial.println(motorSpeed);
  analogWrite(motorPin,motorSpeed);
}
