#include <Servo.h>
Servo Servo1;
const int capteur=8;
int etatCapteur=0;

void setup() {
  Servo1.attach(9);
  pinMode(capteur, INPUT);
  Serial.begin(9600);
  Serial.println("initialisation :");  
}

 

void loop() {
  etatCapteur = digitalRead(capteur);
  Serial.println(etatCapteur);
  
  if (etatCapteur == HIGH) {
      Serial.println("LA JE SUIS DEVANT OUVRE TOI");
      Servo1.write(50);
      delay(5000);
      Serial.println("IL N'Y A PLUS PERSONNE");
      Servo1.write(180);
      
      
      }
  else {
      Serial.println("IL N'Y A PERSONNE");
      delay(1200);

      }
}
    
