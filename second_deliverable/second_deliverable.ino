#include <elapsedMillis.h>

const int relay1 = 4;
const int relay2 = 5;
uint32_t period;
//int a, b;
int direct;
int a ;
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
 return angle;
}


void rotate_left_by(int angle){
 turnLeft();
 to_be_rotated_by = angle;
}

void rotate_right_by(int angle){
 turnRight();
 to_be_rotated_by = angle;
}

void extendActuator(){
 digitalWrite(relay1, HIGH);
 digitalWrite(relay2, LOW);
}

void retractActuator(){
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, HIGH);
}

void stopActuator(){
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
}

void moveFixedDistance(int distance){
 const int actuator_speed = 30;
 const int reqtime = distance/30;
 uint32_t period = reqtime * 1000;
 elapsedMillis timeElapsed;
 
 while(timeElapsed < period){
  extendActuator();
 }

}

void moveFixedDistanceDown(int distance){
 const int actuator_speed = 30;
 const int reqtime = distance/30;
 uint32_t newperiod = reqtime * 1000;
 elapsedMillis newtimeElapsed;
 
 while(newtimeElapsed < newperiod){
  retractActuator();
 }

}

void singleFunction(int distance){
 Serial.println(direct);
 Serial.println("starting");
 
 if(1 == direct){
  Serial.println("starting2");
  moveFixedDistance(distance);
 }
 else{
  Serial.println("starting3");
  moveFixedDistanceDown(distance);
 }
 
 if(1 == direct){
  direct = 0;
 }
 else{
  direct = 1;
 }
 
 delay(15000);
}

void repeat(int distance){ 
 for(int i = 0 ; i < 2 ; i++)
  singleFunction(distance);
}

void setup() {
 pinMode(2,INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2),count,FALLING);
 encoderValue=0;
 // put your setup code here, to run once:
 pinMode(7, OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 a = 0;
 direct = 1;
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
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
  delay(1000) ;
  Serial.println("the first coordinate is ");
  Serial.print(x);
  if(x > 0)
   rotate_right_by(x);  
  delay(15000); 
  if(y>0)
   repeat(y) ;
 }
 
 delay(500);

}
