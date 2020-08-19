void setup(){
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  while(Serial.available() > 0){
    char number = (char) Serial.read();

    if(number == '0'){
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      analogWrite(9, 250);
    }

     if(number == '1'){
       digitalWrite(8, LOW);
       digitalWrite(7, HIGH);
       analogWrite(9, 250);
     }

     if(number == 'a'){
       digitalWrite(8, HIGH);
       digitalWrite(7, LOW);
       analogWrite(9, 0);
     }

   }

   delay(500);

 }
