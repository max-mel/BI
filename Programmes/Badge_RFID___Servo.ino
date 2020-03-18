#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

RFID RFID(10,9);

int UID[5]={};
int MASTERKEY[5]={201,110,120,193,30}; 
Servo monServo;

bool statut = 1;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  RFID.init();
  monServo.attach(5); // Servo connecté à la pin 5.  
}

void loop()
{
    if (RFID.isCard()) {  

          /* Lecture du tag */
          if (RFID.readCardSerial()) 
          {        
            for(int i=0;i<=4;i++)
            {
              UID[i]=RFID.serNum[i];

            }
 
          }
          
          if (UID[0] == MASTERKEY[0]   // Si l'UID 0  est égale à 201
           && UID[1] == MASTERKEY[1]   // Et si l'UID 1  est égale à 110
           && UID[2] == MASTERKEY[2]   // Et si l'UID 2  est égale à 120
           && UID[3] == MASTERKEY[3]   // Et si l'UID 3  est égale à 193
           && UID[4] == MASTERKEY[4])  // Et si l'UID 4  est égale à 30
            {
              monServo.write(120);
              delay(5000);
              monServo.write(45);
            }   
    }} 
