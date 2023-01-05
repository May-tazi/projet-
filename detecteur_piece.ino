const int CapteurPiece=3;
int piece=0;
int val1=0;
int val2=0;
int val3=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(CapteurPiece,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  piece=digitalRead(CapteurPiece);// lecture de la valeur d'entrée
  Serial.println(piece);

  if (piece==1){
    val1=1; //met à la position 1 les roues 
    val2=1; //met à la position 1 les roues 
    val3=1; //met à la position 1 les roues
    delay(10);
  }

}
