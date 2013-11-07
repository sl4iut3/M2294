const char pinMux = 4;
const char pinAff[8]={13,12,6,7,8,10,9,11};
const char masques[8]={1,2,4,8,16,32,64,128};                      // Liste des masques pour obtenir l'état d'un seul segment
 
const unsigned char val=0x5E;                       // Mettre la bonne valeur donnée ci-dessus
 
void setup()
{
    char i;
 
    for (i=0;i<8;i++) pinMode(pinAff[i],OUTPUT);    // Déclaration des 8 sorties des afficheurs
    pinMode(pinMux,OUTPUT);                         // + sortie de multiplexage (choix de l'afficheur)
    digitalWrite(pinMux,1);                         // sur l'afficheur 1
}

void affiche(char val) {
    char i;
    unsigned char c;
 
    for (i=0;i<8;i++)
    {
          delay(300);                               // Inutile ! permet de ralentir pour éventuellement trouver les erreurs
          c = val & masques[i] ;                               // c dépend de val,masques et du segment qui nous intéresse (donc i)
          if (c == 0 ) digitalWrite(pinAff[i],0);        // Modifie successivement l'état des segments a (ou patte 13)
                else digitalWrite(pinAff[i],1);           // puis b (ou patte 12) ... selon la valeur de c
    }
}

void loop()
{
  affiche(val);
}
