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

}

void Pointer::moveInX(){

}

void Pointer::moveInY(){

}

void Pointer::restPosition(){

}

void Pointer::getPosition(){

}
