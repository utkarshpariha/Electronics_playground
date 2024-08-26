
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
 motorSpeed = map(potVal,0,1023,0,255);
  Serial.print("motorSpeed");
  Serial.println(motorSpeed);
  analogWrite(motorPin,motorSpeed);
}