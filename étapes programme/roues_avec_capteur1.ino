#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 

int deg=0;
int arret = 97;
int marche_avant=101;
const int capteur_initialisation= 6;
const int capteur_motif= 5;
int tours= 0;
int passage_motif=0;
int a=0;
int b=0;


void setup() {
  
  myservo.attach(7);  //Servo branché sur la borne digitale 7
  pinMode(capteur_initialisation, INPUT);
  pinMode(capteur_motif, INPUT);
  Serial.begin(9600);
  myservo.write(marche_avant);

  
} 

void loop() {

  //pour l'initialisation:
  Serial.println(tours);
  Serial.println("le motif est:");
  Serial.println(passage_motif);

  
  if ((digitalRead(capteur_initialisation)==1)&&a==0){
    tours=tours+1;
    a=1;
  }
  if ((digitalRead(capteur_initialisation)==0)){
    a=0;
  }
  if ( tours>=1){
    //pour savoir le motif:
    if ((digitalRead(capteur_motif)==1)&&b==0){
      passage_motif=passage_motif+1;
      b=1;
    }
  
    if ((digitalRead(passage_motif)==0)){
      b=0;
    }
  
    if (passage_motif==9){
      myservo.write(arret);
    }
  }
  
} 
 
