int capteurlaser = 0;
int capteurlum = 1;
int lum;
int x = 110; // Seuil de luminosité exterieur à partir duquel la lampe s'allume
int y = 350; // Seuil de luminosité exterieur à partir duquel la lampe s'allume
int ampoule = 2;
int M;
void setup() {
  pinMode(lum,OUTPUT);
  pinMode(ampoule,OUTPUT);
  pinMode(capteurlaser,INPUT);
  pinMode(capteurlum,INPUT);
  digitalWrite(ampoule,LOW);
  Serial.begin(9600);
  
  

}

void loop() {
  capteurlaser = analogRead(0);
  capteurlum = analogRead(1);
  Serial.print(capteurlaser);
  Serial.print(" ");
  
  Serial.println(capteurlum);


// Lumiere allume
  if ((capteurlaser > x) && (capteurlum > y)){
    digitalWrite(ampoule,LOW);
    delay(10000);
  }
  if ((capteurlaser < x ) | (capteurlum < y)){
    digitalWrite(ampoule,HIGH); 
    delay(100);
    }}
    

 
  
