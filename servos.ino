#include <Servo.h>

Servo myservo;


bool p = false;

void setup() {
  myservo.attach(10);
}

void loop() {
  if (p){myservo.write(180);} else {myservo.write(0);}
}