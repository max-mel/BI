#include<SoftwareSerial.h>

#define RX 8
#define TX 7
#define LED 2


SoftwareSerial BlueT(RX,TX);
char Data;
void setup(){
Serial.begin(9600);
BlueT.begin(9600);
pinMode(LED, OUTPUT);
digitalWrite(LED,HIGH);
BlueT.print("azert");
}

void loop(){
if (BlueT.available()){
Data=BlueT.read();
  if (Data=='1') {
  //Serial.println("ok");
  digitalWrite(LED, LOW);}

  if (Data=='2') {
  //Serial.println("oui");
  digitalWrite(LED, HIGH);}
}


}
