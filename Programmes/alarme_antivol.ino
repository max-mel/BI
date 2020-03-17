#include<SoftwareSerial.h>
int capteur=0;
#define RX 2
#define TX 3
#define LED 2
int val=0;
int buzzer=4;

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
val=analogRead(capteur);
Serial.println(val);
  if (val >200){
    Serial.println("vol");
    BlueT.print("vol");
    tone(buzzer,500);
    delay(7000);
    noTone(buzzer);
    delay(1000);
}

}
