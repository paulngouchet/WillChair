const int buttonPin = 12;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int ledState = -1;
const int buttonPin1 = 4;
int lastButtonState1 = LOW;
unsigned long lastDebounceTime1 = 0;
unsigned long debounceDelay1 = 50;
int ledState1 = -1;
double encoderValue=0; void count();
double rotation_angle = 0.0;
double to_be_rotated_by = 30;

void turnOff(){
 encoderValue = 0 ;
 digitalWrite(8, HIGH);
 digitalWrite(7, LOW);
 analogWrite(9, 0);
}


void turnRight(){
 encoderValue = 0 ;
 digitalWrite(8, HIGH);
 digitalWrite(7, LOW);
 analogWrite(9, 90);
}


void turnLeft(){
  encoderValue = 0 ;
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  analogWrite(9, 90);
}


void count(){
  encoderValue++;

  if((int) encToAngle(encoderValue) == (int) to_be_rotated_by){
    Serial.println("The instant angle is ");
    Serial.println(encToAngle(encoderValue));
    turnOff();
    encoderValue = 0;
  }

}

double encToAngle(double encoder){
  double angle =  (encoder*360)/8400.0;
  return angle;
}


void setup(){
 pinMode(buttonPin, INPUT);
 pinMode(buttonPin1, INPUT);
 pinMode(2,INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2),count,FALLING);
 encoderValue=0;
 pinMode(7, OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

    if((millis() - lastDebounceTime) > debounceDelay){
      if((buttonState == HIGH) && (ledState < 0)){
        turnRight();
        ledState = -ledState;
        lastDebounceTime = millis();
      }
      else if((buttonState == HIGH) && (ledState > 0)){
        turnOff();
        ledState = -ledState;
        lastDebounceTime = millis();
      }
    }

    int buttonState1 = digitalRead(buttonPin1);

    if((millis() - lastDebounceTime1) > debounceDelay1) {
      if( (buttonState1 == HIGH) && (ledState1 < 0) ) {
        turnLeft();
        ledState1 = -ledState1;
        lastDebounceTime1 = millis();
      }
    else if((buttonState1 == HIGH) && (ledState1 > 0)){
      turnOff();
      ledState1 = -ledState1;
      lastDebounceTime1 = millis();
    }
  }

  Serial.print("Starting\n");
  Serial.print("angle of rotation =");
  rotation_angle = encToAngle(encoderValue);
  Serial.println(rotation_angle);
  Serial.println(encoderValue);

  while(Serial.available() > 0){

    int number =  Serial.parseInt();
    if(number == 10){
      turnRight();
      to_be_rotated_by = 10.0 ;
      Serial.println("to be rotated by is");
      Serial.println(to_be_rotated_by);
    }

     if(number == 15){
       turnLeft();
       to_be_rotated_by = 15.0;
     }

     if(number == 20){
       turnOff();
     }

   }

   delay(500);
 }
