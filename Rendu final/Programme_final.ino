#include <Servo.h> 

//creation d'objet servo 
Servo myservo1;  
Servo myservo2;  
Servo myservo3; 
Servo ServoGain;  


//variables pour controler les vitesses de nos moteurs
int deg=0;
int marche_avant=98; 

//savoir si notre moteur est à l'arret
int attache1=-1;
int attache2=-1;
int attache3=-1;


int valeur=0; //variable qui permet de savoir si on a gagné
int piece=-1;

//roue1
const int capteur_initialisation1= 6;
const int capteur_motif1= 5;


//roue2
const int capteur_initialisation2= 11;
const int capteur_motif2= 12;

//roue3
const int capteur_initialisation3= 13;
const int capteur_motif3= 4;

const int bouton=10;

const int capteur_piece=2;

//motif aleatoire
int motif_aleatoire_roue1=0;
int motif_aleatoire_roue2=0;
int motif_aleatoire_roue3=0;

//variable qui va compter les tours
int tours1= 0;
int tours2= 0;
int tours3= 0;

//variable qui va compter le nombre de motifs
long passage_motif1=-1;
long passage_motif2=-1;
long passage_motif3=-1;


int b1=0;
int b2=0;
int b3=0;

int a=0;

int commencons=0;

int x1;
int x2;
int x3; 

void setup() {
  

  
  randomSeed(analogRead(A1));

  pinMode (bouton, INPUT_PULLUP);
  pinMode(capteur_piece,INPUT);
  
  pinMode(capteur_initialisation1, INPUT);
  pinMode(capteur_motif1, INPUT);

  pinMode(capteur_initialisation2, INPUT);
  pinMode(capteur_motif2, INPUT);

  pinMode(capteur_initialisation3, INPUT);
  pinMode(capteur_motif3, INPUT);
  
  Serial.begin(9600);

}

 void roues(){
  myservo1.attach(7);
  attache1=1;
  myservo2.attach(8);
  attache2=1;
  myservo3.attach(9);
  attache3=1;
  myservo1.write(marche_avant);
  myservo2.write(marche_avant);
  myservo3.write(marche_avant);

  //pour l'initialisation:
  if ((digitalRead(capteur_initialisation1)==1)&&tours1==0){
    tours1++;
  }

  if ((digitalRead(capteur_initialisation2)==1)&&tours2==0){
    tours2++;
  }

  if ((digitalRead(capteur_initialisation3)==1)&&tours3==0){
    tours3++;
  }
    
    while((attache1 != 0)&&(attache2 != 0)&&(attache3 != 0)){
      
      if ( tours1>0){
        if ((digitalRead(capteur_motif1)==1)&&b1==0){
          passage_motif1=passage_motif1+1;
          b1=1;
        }
  
        if ((digitalRead(capteur_motif1)==0)){
        b1=0;
        }

        if (passage_motif1==motif_aleatoire_roue1-1){
          myservo1.detach();
          attache1=0;

        }
      }
      
      if ( tours2>0){
        if ((digitalRead(capteur_motif2)==1)&&b2==0){
          passage_motif2=passage_motif2+1;
          b2=1;
        }
  
        if ((digitalRead(capteur_motif2)==0)){
        b2=0;
        }

        if (passage_motif2==motif_aleatoire_roue2-1){
          myservo2.detach() ;
          attache2=0;
        }
      }

      if ( tours3>0){
        if ((digitalRead(capteur_motif3)==1)&&b3==0){
          passage_motif3=passage_motif3+1;
          b3=1;
        }
  
        if ((digitalRead(capteur_motif3)==0)){
        b3=0;
        }

        if (passage_motif3==motif_aleatoire_roue3-1){
          myservo3.detach();
          attache3=0;
        }
      }
  }

  
  
  if ((x1==x2)&&(x1==x3)){   //étude du cas ou les 3 mêmes motifs sont alignés
    valeur=1;
  }
  else{    
    valeur=0;
  }
}

void monnayeur(){
  ServoGain.attach(3);
  ServoGain.writeMicroseconds(1600);//permet de modifier l'angle du bras du servomoteur en donnant en 
                                    //paramètre la durée de l'impulsion à transmettre au servomoteur.
  
  for(deg=0;deg<1;deg++){
    ServoGain.writeMicroseconds(2000);
    delay(500);
    ServoGain.writeMicroseconds(1100);
    delay(500);}
    
    ServoGain.detach();
 }

void comptePiece(){
  if ((digitalRead(capteur_piece)==1)&&a==0){
    piece=piece+1;
    a=1;
  }
  
  if ((digitalRead(capteur_piece)==0)){
    a=0;
  }
 }


void loop() {
  comptePiece();
  if (piece>0){
    Serial.print(piece);
      //choix aleatoire de 3 motifs
      motif_aleatoire_roue1=random(20, 27);
      motif_aleatoire_roue2=random(20, 27);
      motif_aleatoire_roue3=random(20, 27);
  
      x1 = motif_aleatoire_roue1%7;
      x2 = motif_aleatoire_roue2%7;
      x3 = motif_aleatoire_roue3%7;
    if (digitalRead(bouton)==0){
      piece --;
      commencons=1;
    }
    if (commencons==1){
      roues();
    }

    if (valeur==1){
      monnayeur();
      valeur =0;}
  
    }
   commencons=0;
} 
 
