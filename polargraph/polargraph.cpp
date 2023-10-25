#include <cmath>
#include "Arduino.h"
#include "AFMotor.h"
#include "polargraph.h"


Pointer::Pointer(float a, float b, State c, int steps){
  position.x = a;
  position.y = b;
  state = c;
  motors.m1 = AF_Stepper(steps, 1);
  motors.m2 = AF_Stepper(steps, 2);
}

void Pointer::speed(int v){
  motors.m1.setSpeed(v);
  motors.m2.setSpeed(v);
}

void Pointer::initPosition(coordenates desired position){
  if ( (distance + position.x < - (width / 2)) && ((width / 2) < distance + position.x) && (distance + position.y < 0) && (height < distance + position.y)) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas")
  } else {
    if () {

    } else {
      
    }
  }
}

void Pointer::moveInX(float distance, State direction){
  if ( (distance + position.x < - (width / 2)) && ((width / 2) < distance + position.x) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas")
  } else {
    if (direction == RIGHT) {
      motors.m1.step(1, FORWARD, SINGLE);
      motors.m2.step(1, BACKWARD, SINGLE);
    } else if (direction == LEFT) {
      motors.m1.step(1, BACKWARD, SINGLE);
      motors.m2.step(1, FORWARD, SINGLE);
    }
    position.x += 2 * resolution * ( - 2  * signbit(distance) + 1)
  }
}

void Pointer::moveInY(float distance, State direction){
  if ( (distance + position.y < 0) && (height < distance + position.y) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas")
  } else {
    if (direction == UP) {
      motors.m2.step(1, BACKWARD, SINGLE);
      motors.m1.step(1, BACKWARD, SINGLE);
    } else if (direction == DOWN) {
      motors.m2.step(1, FORWARD, SINGLE);
      motors.m1.step(1, FORWARD, SINGLE);
    }
    position.y += 2 * resolution * ( - 2  * signbit(distance) + 1)
  }
}

void Pointer::restPosition(){
  initPosition(0.0, 0.0);
}

coordenates Pointer::getPosition(){
  return position;
}
