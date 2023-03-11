#include <Servo.h>

Servo ServoGain;
int deg=0;


void setup() {
  // put your setup code here, to run once:
  ServoGain.attach(7);
  Serial.begin(9600);
  ServoGain.writeMicroseconds(1600);//permet de modifier l'angle du bras du servomoteur en donnant en paramètre la durée de l'impulsion à transmettre au servomoteur.
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(deg=0;deg<1;deg++){
    ServoGain.writeMicroseconds(2000);
    delay(500);
    ServoGain.writeMicroseconds(1100);
    delay(500);}

    ServoGain.detach();
  }
  
  
  


               
