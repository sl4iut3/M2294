const char pinMux = 4;
const char pinAff[8]={
  13,12,6,7,8,10,9,11};
const char masques[8]={
  1,2,4,8,16,32,64,128};                      // Liste des masques pour obtenir l'état d'un seul segment

unsigned char val[]={
  0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};                        // Mettre la bonne valeur donnée ci-dessus

void setup()
{
  char i;

  for (i=0;i<8;i++) pinMode(pinAff[i],OUTPUT);    // Déclaration des 8 sorties des afficheurs
  pinMode(pinMux,OUTPUT);                         // + sortie de multiplexage (choix de l'afficheur)
}

void affiche(char val) {
  char i;
  unsigned char c;

  for (i=0;i<8;i++)
  {
    //delay(300);                               // Inutile ! permet de ralentir pour éventuellement trouver les erreurs
    c = val & masques[i] ;                               // c dépend de val,masques et du segment qui nous intéresse (donc i)
    if (c == 0 ) digitalWrite(pinAff[i],0);        // Modifie successivement l'état des segments a (ou patte 13)
    else digitalWrite(pinAff[i],1);           // puis b (ou patte 12) ... selon la valeur de c
  }
}

void loop()
{
  int u,d,j;
  for (d=0;d<10;d++) 
    for (u=0;u<10;u++) {
      for (j=0;j<10;j++) {
        affiche(val[u]);
        digitalWrite(pinMux,1);                         // sur l'afficheur droit
        delay(5);
        affiche(val[d]);
        digitalWrite(pinMux,0);                         // sur l'afficheur gauche
        delay(5);    
      }
    }
}




