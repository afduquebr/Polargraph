#include "Polargraph.h"
#include <Arduino.h>

using namespace std;


Polargraph::Polargraph(float a, float b, State c){
  position.x = a;
  position.y = b;
  state = c;
  resolution = sqrt(2) * radius * 1.8 * M_PI /100;
}

void Polargraph::speed(int v){
  motor1.setSpeed(v);
  motor2.setSpeed(v);
}

void Polargraph::initPosition(float x0, float y0){
  if ( (x0 + position.x < - (width / 2)) && ((width / 2) < x0 + position.x) && (y0 + position.y < 0) && (height < y0 + position.y)) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
  } else {
    if (abs(y0 - position.y) > resolution) {
      if (signbit(x0) == 0) {
        moveInY(y0, UP);
      } else {
        moveInY(y0, DOWN);
      }
    } else if (abs(x0 - position.x) > resolution) {
      if (signbit(x0) == 0) {
        moveInX(x0, RIGHT);
      } else {
        moveInX(x0, LEFT);
      }
    }
  }
}

void Polargraph::moveInX(float newX, State direction){
  if ( (newX + position.x < - (width / 2)) && ((width / 2) < newX + position.x) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
  } else {
    if (direction == RIGHT) {
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    } else if (direction == LEFT) {
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    position.x += 2 * resolution * ( - 2  * signbit(newX) + 1);
  }
}

void Polargraph::moveInY(float newY, State direction){
  if ( (newY + position.y < 0) && (height < newY + position.y) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
  } else {
    if (direction == UP) {
      motor2.step(1, BACKWARD, SINGLE);
      motor1.step(1, BACKWARD, SINGLE);
    } else if (direction == DOWN) {
      motor2.step(1, FORWARD, SINGLE);
      motor1.step(1, FORWARD, SINGLE);
    }
    position.y += 2 * resolution * ( - 2  * signbit(newY) + 1);
  }
}

void Polargraph::restPosition(){
  initPosition(0.0, 0.0);
}

coordenates Polargraph::getPosition(){
  return position;
}
