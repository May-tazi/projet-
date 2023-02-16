#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo    //7
Servo myservo2;  // create servo object to control a servo    //8
Servo myservo3;  // create servo object to control a servo    //9

int deg=0;
int marche_avant=98; //101
int marche_arret=96;
int arret=0;


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

const int capteur_piece=3;

//motif aleatoire
int motif_aleatoire_roue1=0;
int motif_aleatoire_roue2=0;
int motif_aleatoire_roue3=0;

int tours1= 0;
int tours2= 0;
int tours3= 0;


long passage_motif1=-1;
long passage_motif2=-1;
long passage_motif3=-1;

int num_motif=0;

int b1=0;
int b2=0;
int b3=0;

int commencons=0;


int x1;
int x2;
int x3; 


/*const int capteur_piece=3;
//int ini_piece=0;
int piece=0;*/



void setup() {

  pinMode (bouton, INPUT_PULLUP);
  pinMode(capteur_piece,INPUT);
  
  
  randomSeed(analogRead(A1));

  pinMode(capteur_initialisation1, INPUT);
  pinMode(capteur_motif1, INPUT);

  pinMode(capteur_initialisation2, INPUT);
  pinMode(capteur_motif2, INPUT);

  pinMode(capteur_initialisation3, INPUT);
  pinMode(capteur_motif3, INPUT);
  
  Serial.begin(9600);


  motif_aleatoire_roue1=random(20, 27);
  motif_aleatoire_roue2=random(20, 27);
  motif_aleatoire_roue3=random(20, 27);
  


  
  x1 = motif_aleatoire_roue1%7;
  x2 = motif_aleatoire_roue2%7;
  x3 = motif_aleatoire_roue3%7;

  Serial.println(x1);
  Serial.println(x2);
  Serial.println(x3);

  
  /*switch (x){
    case 0:
    Serial.println("pique");
    break;
    case 1:
    Serial.println("raisin");
    break;
    case 2:
    Serial.println("coeur"); //0?
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
  */
  
} 

void roues(){
  myservo1.attach(7);
  myservo2.attach(8);
  myservo3.attach(9);
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

    
    while((myservo1.read()!=marche_arret)&&(myservo2.read()!=marche_arret)&&(myservo3.read()!=marche_arret)){
      
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

        }
      }
      Serial.println(passage_motif1);
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
        }
      }
  }

  if ((x1==x2)&&(x1==x3)){
    Serial.println("c'est gagné");
  }
  else{
    Serial.println("dommage");
  }
}

/*void comptePiece(){
  //if ((digitalRead(capteur_piece)==1)&&a==0){
    //piece=piece+1;
    //a=1;
  //}
  
  //if ((digitalRead(capteur_piece)==0)){
    //a=0;
  //}

 //Serial.println(piece);
 //delay(200);
//}*/


void loop() {
  //if (comptePiece>0){
    if (digitalRead(bouton)==0){
      commencons=1;
    }
    if (commencons==1){
    roues();
    
  }
   
  
  
} 
 
