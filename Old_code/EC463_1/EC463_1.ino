void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);

}

void loop(){
  while(Serial.available() > 0 ){
    char number = (char) Serial.read();
    if(number == '0'){
      turnRight();
    }
    if(number == '1'){
      turnLeft();
    }
    if(number == 'a'){
      turnOff();
    }
  }

  delay(500);

}


void turnOff(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  analogWrite(9, 0);
}


void turnRight(){
 digitalWrite(8, HIGH);
 digitalWrite(7, LOW);
 analogWrite(9, 250);
}

void turnLeft(){
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  analogWrite(9, 250);
}
