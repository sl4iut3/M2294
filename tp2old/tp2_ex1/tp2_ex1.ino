const char pinMux = 4;
const char pinAff[8]={13,12,6,7,8,10,9,11};
 
const unsigned char val=0x7a;
 
void setup()
{
    char i;
    for (i=0;i<8;i++) pinMode(pinAff[i],OUTPUT);    // Déclaration des 8 sorties des afficheurs
    pinMode(pinMux,OUTPUT);                         // + sortie de multiplexage (choix de l'afficheur)
    digitalWrite(pinMux,1);                         // sur l'afficheur 1
}
 
void loop()
{
    char i,s;
    unsigned char c;
 
    for (i=0;i<8;i++)
    {
          delay(300);                               // Inutile ! permet de ralentir pour éventuellement trouver les erreurs
          c = (val>>(7-i))&1 ;                               // c dépend nécessairement de val et du segment qui nous intéresse (donc i)
          digitalWrite(pinAff[i],c);                      // Modifie successivement l'état des segments a (ou patte 13) puis b (ou patte 12) ...
    }
}
