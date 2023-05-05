#include <Encoder.h>//Lirairie externe pour utiliser des encodeurs

/////ENCODEURS

Encoder encodeurAvG(18,31);
Encoder encodeurAvD(19,38);
Encoder encodeurArG(3,49);
Encoder encodeurArD(2,A1);


//Fonction générique
float distanceLowLevel(Encoder encodeur){//Retourne une distance en cm
  
  return encodeur.read()/1440.0*8.0*PI;
  /*Diviser par 1440 c'est le nombre de "clic" par tour de roue
  Multiplier par pi*8 car les roues ont un diamètre de 8 cm*/
}

void resetEncoder(){
  encodeurAvG.write(0);
  encodeurAvD.write(0);
  encodeurArG.write(0);
  encodeurArD.write(0);
}


//Fonctions pour obtenir la valeur d'encodeur de chaque roue
float distanceAvG(){
  return -distanceLowLevel(encodeurAvG);//Négatif pour que la valeur augmente en avançant
}

float distanceAvD(){
  return distanceLowLevel(encodeurAvD);
}

float distanceArG(){
  return -distanceLowLevel(encodeurArG);//Négatif pour que la valeur augmente en avançant
}

float distanceArD(){
  return distanceLowLevel(encodeurArD);
}

//Fonction principale pour obtenir la distance parcourue globale
float distance(){
  return (distanceAvD() + distanceAvG() + distanceArG() + distanceArD())/4;
}


//Fonctions pour obtenir la distance parcourue par un seul côté
float distanceDroite(){
  return(distanceAvD() + distanceArD())/2;
}

float distanceGauche(){
  return (distanceAvG() + distanceArG())/2;
}
