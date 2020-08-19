//defining Pins names for the code
int pwm=9; int forward=7; int reverse=8;
double encoderValue=0; void count(void);

void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),count,FALLING);
  encoderValue=0;
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  analogWrite(9, 50);
  Serial.print("Starting\n");
  Serial.print("angle of rotation =");
  Serial.println(encoderValue);
  Serial.println(encToAngle(encoderValue));
  delay(250);
}

void count(){
  encoderValue++;
}

double encToAngle(double encoder){
  double angle =  (encoder*360)/8100.0;
  return angle;
}
