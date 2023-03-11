#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int deg=0;
int arret = 90;


void setup() {
  
  myservo.attach(7);  //Servo branché sur la borne digitale 7
  //Initiation d'une connexion série 9600bauds
  
  Serial.begin(9600);
} 

void loop() {
  deg = map(analogRead(0),0,1023,0,180);
  myservo.write(deg);

  
  Serial.println(deg);
  
} 
 
