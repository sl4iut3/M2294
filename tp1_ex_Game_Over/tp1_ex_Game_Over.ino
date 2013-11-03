

#define bp0 2

char ledR[]={
  13,10,6};
char ledV[]={
  11,8,7};
char ledO[]={
  12,9};

char etatPasse=0, etatPresent=0, alarme=0;

unsigned long t;

void setup() {
  int i;
  for (i=0;i<3;i++) pinMode(ledR[i],OUTPUT);
  for (i=0;i<3;i++) pinMode(ledV[i],OUTPUT);
  for (i=0;i<2;i++) pinMode(ledO[i],OUTPUT);
  pinMode(bp0,INPUT);
  Serial.begin(9600);
}

void loop() {
  int i;
  if (alarme==0) {
    // allume l'alarme toutes les 3 secondes
    if ( (millis()-t)>3000 ) {
      t=millis();
      alarme=1;
      for (i=0;i<2;i++) digitalWrite(ledO[i],HIGH);
      for (i=0;i<3;i++) digitalWrite(ledR[i],LOW);
      for (i=0;i<3;i++) digitalWrite(ledV[i],LOW);
    }
  } 
  else {
    // alluime rouge si 3s depasse
    if ( (millis()-t)>3000 ) { 
      for (i=0;i<3;i++) digitalWrite(ledR[i],HIGH);
      for (i=0;i<2;i++) digitalWrite(ledO[i],LOW);
    }
    // teste appui sur bp0 (marche)
    etatPresent=digitalRead(bp0);
    if ( (etatPasse==LOW)&&(etatPresent==HIGH) ){ 
      for (i=0;i<3;i++) digitalWrite(ledR[i],LOW);
      for (i=0;i<2;i++) digitalWrite(ledO[i],LOW);
      for (i=0;i<3;i++) digitalWrite(ledV[i],HIGH);
      alarme=0;
      t=millis();
    }
    etatPasse=etatPresent;
  }
  delay(50);
}

