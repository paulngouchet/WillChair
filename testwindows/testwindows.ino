void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop(){
   while(Serial.available() > 0 ){
    int x =  Serial.parseInt();
    int y = Serial.parseInt();

    if(x == 7 && y == 11 ){
      Serial.println("getting there");
      turnRight();
      turnLeft();
    }

     if(x == 15){
       turnLeft();
     }

    if(x == 20){
      turnOff();
    }
  }

delay(500);
}


void turnOff(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}


void turnRight(){

  for(int i = 0 ; i < 2 ; i++){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }

}


void turnLeft(){
  for(int i = 0 ; i < 3 ; i++ ){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }
}
