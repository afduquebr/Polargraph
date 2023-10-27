#include "Polargraph.h"
#include <Arduino.h>

using namespace std;


Polargraph::Polargraph(float a, float b){
  position.x = a;
  position.y = b;
  resolution = sqrt(2) * radius * M_PI /100;
}

void Polargraph::speed(int v){
  motor1.setSpeed(v);
  motor2.setSpeed(v);
}

bool Polargraph::initPosition(float x0, float y0){
  bool stopX = 0;
  bool stopY = 0;
  if (abs(y0 - position.y) > resolution) {
    stopY = moveInY(y0);
  } else if (abs(x0 - position.x) > resolution) {
    stopX = moveInX(x0);
  }
  return stopX;
}

bool Polargraph::moveInX(float newX){
  bool stop = 0;
  if ( (newX < - (width / 2)) && ((width / 2) < newX) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
      stop = 1;
  } else {
    if ((newX - position.x) > 0) {
      motor2.step(1, FORWARD, SINGLE);
      motor1.step(1, FORWARD, SINGLE);
    } else if ((newX - position.x) < 0) {
      motor2.step(1, BACKWARD, SINGLE);
      motor1.step(1, BACKWARD, SINGLE);
    }
    position.x += 2 * resolution * copysign(1.0, (newX - position.x));
    if (abs(newX - position.x) < resolution) {
      Serial.println(abs(newX - position.x));
      stop = 1;
    }
    return stop;
  }
}

bool Polargraph::moveInY(float newY){
  bool stop = 0;
  if ( (newY < 0.0) && (height < newY) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
    stop = 1;
  } else {
    if ((newY - position.y) < 0) {
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    } else if ((newY - position.y) > 0) {
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    position.y += 2 * resolution * copysign(1.0, (newY - position.y));
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
