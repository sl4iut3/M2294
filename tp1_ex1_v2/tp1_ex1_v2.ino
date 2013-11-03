

#define p0 6
#define bp0 2

char etatPasse=0, etatPresent=0, etatSortie=0;

void setup() {
  pinMode(bp0,INPUT);
  pinMode(p0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  etatPasse=etatPresent;
  etatPresent=digitalRead(bp0);
  if ( (etatPasse==LOW)&&(etatPresent==HIGH) ) 
    etatSortie=~etatSortie;
  if (etatSortie!=0) {
    digitalWrite(p0,HIGH);
  } else {
    digitalWrite(p0,LOW);
  }
  delay(50);
}
