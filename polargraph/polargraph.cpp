#include "Polargraph.h"
#include <Arduino.h>

using namespace std;


Polargraph::Polargraph(float a, float b){
  position.x = a;
  position.y = b;
  resolution = sqrt(2) * radius * 1.8 * M_PI /100;
}

void Polargraph::speed(int v){
  motor1.setSpeed(v);
  motor2.setSpeed(v);
}

bool Polargraph::initPosition(float x0, float y0){
  bool stopX = 0;
  bool stopY = 0;
  if (stopY == 0) {
    stopY = moveInY(y0);
  } else if (stopX == 0) {
    stopX = moveInX(x0);
  }
  return stopX;
}

bool Polargraph::moveInX(float newX){
  bool stop = 0;
  if ( (newX < - (width / 2)) && ((width / 2) < newX) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
  } else {
    if ((newX - position.x) > 0) {
      motor2.step(1, FORWARD, SINGLE);
      motor1.step(1, BACKWARD, SINGLE);
    } else if ((newX - position.x) < 0) {
      motor2.step(1, BACKWARD, SINGLE);
      motor1.step(1, FORWARD, SINGLE);
    }
    position.x += 2 * resolution * ( - 2  * signbit(newX - position.x) + 1);
    if (abs(newX - position.x) < resolution) {
      stop = 1;
    }
    return stop;
  }
}

bool Polargraph::moveInY(float newY){
  bool stop = 0;
  if ( (newY < 0.0) && (height < newY) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
  } else {
    if ((newY - position.y) < 0) {
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    } else if ((newY - position.y) > 0) {
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    position.y += 2 * resolution * ( - 2  * signbit(newY - position.y) + 1);
    if (abs(newY - position.y) < resolution) {
      stop = 1;
    }
    return stop;
  }
}

bool Polargraph::restPosition(){
  return initPosition(0.0, 0.0);
}

coordenates Polargraph::getPosition(){
  return position;
}
