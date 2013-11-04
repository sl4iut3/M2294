

#define ledRouge 6
#define ledVerte 7

#define bp0 2
#define bp1 3
#define bp2 A0

char etatPasse_bp0=0, etatPasse_bp2=0, etatPresent=0;

void setup() {
  pinMode(bp0,INPUT);
  pinMode(bp1,INPUT);
  pinMode(bp2,INPUT);
  pinMode(ledRouge,OUTPUT);
  pinMode(ledVerte,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // teste appui sur bp0 (marche)
  etatPresent=digitalRead(bp0);
  // si appui allume ledVerte
  if ( (etatPasse_bp0==LOW)&&(etatPresent==HIGH) ) 
    digitalWrite(ledVerte,HIGH);
  etatPasse_bp0=etatPresent;
  // teste appui bp2
  etatPresent=digitalRead(bp2);
  // si appui eteint ledVerte
  if ( (etatPasse_bp2==HIGH)&&(etatPresent==LOW) ) 
    digitalWrite(ledVerte,LOW);
  etatPasse_bp2=etatPresent;
  // si bp2==low allume ledRouge sinon eteint ledRouge
  if (etatPresent==LOW) 
    digitalWrite(ledRouge,HIGH);
    else
    digitalWrite(ledRouge,LOW);
  delay(50);
}
