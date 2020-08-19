#include <elapsedMillis.h>

const int relay1 = 4;
const int relay2 = 5;
uint32_t period;
int direct;
int a ;

void setup() {
  a = 0;
  direct = 1;
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Serial.begin(9600);
}

void extendActuator() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

void retractActuator() {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
}


void stopActuator() {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void moveFixedDistance(int distance)
{
  const int actuator_speed = 30;
  const int reqtime = distance/30;
  uint32_t period = reqtime * 1000;
  elapsedMillis timeElapsed;

   while(timeElapsed < period  ){
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

  if (1 == direct){
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

void loop(){

  if(a == 0 ){
    a++;
    repeat(400) ;
  }
}
