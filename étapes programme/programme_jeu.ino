#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 

int deg=0;
int marche_avant=101;
int arret=0;

const int capteur_initialisation= 6;
const int capteur_motif= 5;
const int bouton=10;
const int capteur_piece=3;

int motif_aleatoire_roue1=0;
int tours= 0;
long passage_motif=0;
int num_motif=0;
int a=0;
int b=0;
int commencons=0;
int x; 


const int capteur_piece=3;
int ini_piece=0;
int piece=0;



void setup() {

  pinMode (bouton, INPUT_PULLUP);
  pinMode(capteur_piece,INPUT);

  
  randomSeed(analogRead(A1));

  pinMode(capteur_initialisation, INPUT);
  pinMode(capteur_motif, INPUT);
  Serial.begin(9600);
  myservo.write(marche_avant);
  motif_aleatoire_roue1=random(10, 30);
  
  Serial.println(motif_aleatoire_roue1);

  x = motif_aleatoire_roue1%7;
  Serial.println("eeeeeeee");
  Serial.println(x);
  switch (x){
    case 0:
    Serial.println("pique");
    break;
    case 1:
    Serial.println("raisin");
    break;
    case 2:
    Serial.println("coeur");
    break;
    case 3:
    Serial.println("ananas");
    break;
    case 4:
    Serial.println("trefle");
    break;
    case 5:
    Serial.println("un");
    break;
    case 6:
    Serial.println("carreau");
    break;
    case 7:
    Serial.println("cerises");
    break;
  }

  
} 

void roues(){
  if (arret==0){
    myservo.attach(7);  //Servo branché sur la borne digitale 7
  }

  //0 qd on poussé
  //1 relaché
  //Serial.println(digitalRead(bouton));

  //pour l'initialisation:

  Serial.println(tours);

  
  //Serial.print("le motif est: ");
  //Serial.println(passage_motif);


  //Serial.print("testtttt: ");
  //Serial.println(digitalRead(capteur_motif));
  
 
  //compte les tours
  if ((digitalRead(capteur_initialisation)==1)&&a==0){
    tours=tours+1;
    a=1;
  }
  
  if ((digitalRead(capteur_initialisation)==0)){
    a=0;
  }

  
  
  if ( tours>=1){
    //pour savoir le motif:
    //1 quand on est sur le noir
    if ((digitalRead(capteur_motif)==1)&&b==0){
      passage_motif=passage_motif+1;
      b=1;
    }
  
    if ((digitalRead(capteur_motif)==0)){
      b=0;
    }


  //on s'arrete quand nous sommes sur le motif défni aléatoirement
    if (passage_motif==motif_aleatoire_roue1){
    //if (tours==9){ 
      //myservo.write(arret);
      myservo.detach() ;
      arret=1;


    }
  }
}

void comptePiece(){
  if ((digitalRead(capteur_piece)==1)&&a==0){
    piece=piece+1;
    a=1;
  }
  
  if ((digitalRead(capteur_piece)==0)){
    a=0;
  }

 Serial.println(piece);
 delay(200);
}


void loop() {
  if (comptePiece>0){
    if (digitalRead(bouton)==0){
      commencons=1;
    }
    if (commencons==1){
    roues();
    }
  }
   
  
  
} 
 
