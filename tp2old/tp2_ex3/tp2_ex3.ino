const char pinMux = 4;
const char pinAff[8]={
  13,12,6,7,8,10,9,11};

// maladroit: ordre des bits inversés % à la documentation
//const unsigned char val[10]={B00111111,..,...};     // Vous avez ici l'état des segments pour afficher le chiffre 0. 
const unsigned char val[]={
  0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};     // Vous avez ici l'état des segments pour afficher le chiffre 0. 

unsigned long t;

void setup()
{
  char i;
  for (i=0;i<8;i++) pinMode(pinAff[i],OUTPUT);    // Déclaration des 8 sorties des afficheurs
  pinMode(pinMux,OUTPUT);                         // + sortie de multiplexage (choix de l'afficheur)
}

void loop()
{
  char i,s;
  unsigned char c;
  for (s=0;s<10;s++) {
    //delay(500);
    for (i=0;i<8;i++)
    {
      //delay(300);                               // Inutile ! permet de ralentir pour éventuellement trouver les erreurs
      c = (val[s]>>(7-i))&1 ;                               // c dépend nécessairement de val et du segment qui nous intéresse (donc i)
      digitalWrite(pinAff[i],c);      // Modifie successivement l'état des segments a (ou patte 13) puis b (ou patte 12) ...
    }
    // temp du comptage
    t=millis();
    while( (millis()-t)<500 ) {
      // gestion du multiplexage
      digitalWrite(pinMux,1);                         // sur l'afficheur 1
      delay(10);
      digitalWrite(pinMux,0);                         // sur l'afficheur 1
      delay(10);
    }

  }
}




