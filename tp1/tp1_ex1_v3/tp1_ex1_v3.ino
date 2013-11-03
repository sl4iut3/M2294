

#define p0 6
#define bp0 2
#define bp2 A0

char etatPasse_bp0=0, etatPasse_bp2=0, etatPresent=0, etatSortie=0;

void setup() {
  pinMode(bp0,INPUT);
  pinMode(bp2,INPUT);
  pinMode(p0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // teste appui sur bp0
  etatPresent=digitalRead(bp0);
  if ( (etatPasse_bp0==LOW)&&(etatPresent==HIGH) ) 
    etatSortie=HIGH;
  etatPasse_bp0=etatPresent;
  // teste relachement bp2
  etatPresent=digitalRead(bp2);
  if ( (etatPasse_bp2==LOW)&&(etatPresent==HIGH) ) 
    etatSortie=LOW;
  etatPasse_bp2=etatPresent;
  // gestion led
  if (etatSortie==HIGH) {
    digitalWrite(p0,HIGH);
  } else {
    digitalWrite(p0,LOW);
  }
  delay(50);
}
