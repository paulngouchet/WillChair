const int buttonPin = 12;  // the number of the pushbutton pin// the current state of the output pin
int lastButtonState = LOW;   // the previous reading from the input pin
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int ledState = -1;
const int buttonPin1 = 4;    // the number of the pushbutton pin                // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay1 = 50;    // the debounce time; increase if the output flickers
int ledState1 = -1;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if((millis() - lastDebounceTime) > debounceDelay){
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"

    if((buttonState == HIGH) && (ledState < 0)){
      Serial.println("it is working ");
      turnRight(); //turn LED on
      ledState = -ledState; //now the LED is on, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }
    else if((buttonState == HIGH) && (ledState > 0)){
      turnOff(); //turn LED off
      ledState = -ledState; //now the LED is off, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }//close if/else

  }

  int buttonState1 = digitalRead(buttonPin1);

  if((millis() - lastDebounceTime1) > debounceDelay1){
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if((buttonState1 == HIGH) && (ledState1 < 0)){
      Serial.println("it is working 2 ");
      turnLeft(); //turn LED on
      ledState1 = -ledState1; //now the LED is on, we need to change the state
      lastDebounceTime1 = millis(); //set the current time
    }
    else if((buttonState1 == HIGH) && (ledState1 > 0)){
      turnOff(); //turn LED off
      ledState1 = -ledState1; //now the LED is off, we need to change the state
      lastDebounceTime1 = millis(); //set the current time
    }//close if/else

  }


  while(Serial.available() > 0){
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
