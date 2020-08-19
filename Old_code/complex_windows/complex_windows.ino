double encoderValue=0; void count();
double rotation_angle = 0.0;
double to_be_rotated_by = 0.0;

void turnOff(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  analogWrite(9, 0);
  encoderValue = 0 ;
}


void turnRight(){
  encoderValue = 0 ;
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  analogWrite(9, 80);
}


void turnLeft(){
  encoderValue = 0 ;
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  analogWrite(9, 80);
}



void count(){

  encoderValue++;

  if((int) encToAngle(encoderValue) == (int) to_be_rotated_by){
    Serial.println("The instant angle is ");
    Serial.println(encToAngle(encoderValue));
    turnOff();
    encoderValue = 0 ;
  }
}

double encToAngle(double encoder){
  double angle =  (encoder*360)/8400.0;
  return angle ;
}


void rotate_left_by(int angle){
  turnLeft();
  to_be_rotated_by = angle;
}

void rotate_right_by(int angle){
  turnRight();
  to_be_rotated_by = angle ;
}

void setup(){
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),count,FALLING);
  encoderValue=0;
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.print("Starting\n");
  Serial.print("angle of rotation =");
  rotation_angle = encToAngle(encoderValue);
  Serial.println(rotation_angle);
  Serial.println(encoderValue);

  while(Serial.available() > 0){
    int x =  Serial.parseInt();
    int y =  Serial.parseInt();
    delay(1000);
    Serial.println("the first coordinate is ");
    Serial.print(x);

    if(x > 0)
      rotate_right_by(x);

    delay(15000);

     if(y>0)
     rotate_left_by(y);


  }

  delay(500);

}
