#include <Encoder.h>

/////Encodeurs

Encoder encodeurAvG(18,31);
Encoder encodeurAvD(19,38);
Encoder encodeurArG(3,49);
Encoder encodeurArD(2,A1);


//Fonction générique
long distanceLowLevel(Encoder encodeur){
  
    //long pour éviter l'overflow
  return encodeur.read()/1000;//diviser par 1000 car c'est environ un tour de shaft
}

void resetEncoder(){
  encodeurAvG.write(0);
  encodeurAvD.write(0);
  encodeurArG.write(0);
  encodeurArD.write(0);
}

long distanceAvG(){
  return -distanceLowLevel(encodeurAvG);
}

long distanceAvD(){
  return distanceLowLevel(encodeurAvD);
}

long distanceArG(){
  return -distanceLowLevel(encodeurArG);
}

long distanceArD(){
  return distanceLowLevel(encodeurArD);
}

long distance(){
  return (distanceAvD() + distanceAvG() + distanceArG() + distanceArD())/4;
}

long distanceDroite(){
  return(distanceAvD() + distanceArD())/2;
}

long distanceGauche(){
  return (distanceAvG() + distanceArG())/2;
}
