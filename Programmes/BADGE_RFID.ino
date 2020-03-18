#include <SPI.h>
#include <RFID.h>

RFID RFID(10,9);

int UID[5];

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  RFID.init();  

}

void loop()
{
    if (RFID.isCard()) {  
          if (RFID.readCardSerial()) {        
            Serial.print("L'UID est: ");
            for(int i=0;i<=4;i++)
            {
              UID[i]=RFID.serNum[i];
              Serial.print(UID[i],DEC);
              Serial.print(".");
            }
            Serial.println("");
          }          
          RFID.halt();
    }
    delay(100);    }
