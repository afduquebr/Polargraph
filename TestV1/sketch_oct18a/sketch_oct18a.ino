// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor1.setSpeed(1);  // 10 rpm   
  motor2.setSpeed(1);  // 10 rpm   
}

void loop() {
//   motor1.step(10, FORWARD, SINGLE); 
//   motor2.step(10, FORWARD, SINGLE); 
//   motor1.step(10, BACKWARD, SINGLE); 
//   motor2.step(10, BACKWARD, SINGLE); 
  
}