
#define bp0 2
#define p0 6

void setup() {
  pinMode(bp0,INPUT);
  pinMode(p0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(bp0)==HIGH) {
    digitalWrite(p0,HIGH);
  } else {
    digitalWrite(p0,LOW);
  }
  delay(50);
}
