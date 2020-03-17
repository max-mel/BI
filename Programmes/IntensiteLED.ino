#include<SoftwareSerial.h>
#define RX 8
#define TX 7
#define LEDS 9
#define LEDC 6
SoftwareSerial BlueT(RX,TX);
int PWM=0;
int PWM2=0;
char Data;
void setup(){
Serial.begin(9600);
BlueT.begin(9600);
pinMode(LEDC, OUTPUT);
pinMode(LEDS, OUTPUT);
}

void loop(){
if (BlueT.available()){
Data=BlueT.read();
  if (Data=='X') {
  PWM=BlueT.parseInt();
  Serial.println(PWM);
  analogWrite(LEDS, PWM);}

  if (Data=='Y') {
  PWM2=BlueT.parseInt();
  Serial.println(PWM2);
  analogWrite(LEDC, PWM2);}
}
}
