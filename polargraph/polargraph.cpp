// Polargraph library
// Last Update: November 8th, 2023.
// Andrés Felipe Duque Bran


#include "Polargraph.h"

using namespace std;

// Definition of the constructor
Polargraph::Polargraph(float a, float b) {
  // Defining initial position of the pointer
  position.x = a;
  position.y = b;
  // Determination of resolution
  resolution = sqrt(2) * radius * M_PI /100;
}

// Set speed for the displacement
void Polargraph::speed(int v) {
  // Set same speed for both engines
  // v is set in rpm
  motor1.setSpeed(v);
  motor2.setSpeed(v);
}

// Method for getting to a certain point in grid
bool Polargraph::initPosition(float x0, float y0) {
  // Bool variables to control position of pointer wrt target
  bool stopX = 0;
  bool stopY = 0;
  // Move in Y and then in X
  if (abs(y0 - position.y) > resolution) {
    stopY = moveInY(y0);
  } else if (abs(x0 - position.x) > resolution) {
    stopX = moveInX(x0);
  }
  // Returns True when movement in X is finished
  return stopX;
}

// Method for horizontal displacement
bool Polargraph::moveInX(float newX) {
  // Bool variables to control x position of pointer wrt target
  bool stop = 0;
  // Warning in case desired position is out of Canvas
  if ( (newX < - (width / 2)) && ((width / 2) < newX) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
      stop = 1;
  } else {
    if ((newX - position.x) > 0) {
      // Move in +X direction
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    } else if ((newX - position.x) < 0) {
      // Move in -X direction
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    // Redefine pointer position after step
    position.x += 2 * resolution * copysign(1.0, (newX - position.x));
    if (abs(newX - position.x) < resolution) {
      stop = 1;
    }
    // Returns True when target position is reached
    return stop;
  }
}

// Method for vertical displacement
bool Polargraph::moveInY(float newY) {
  // Bool variables to control y position of pointer wrt target
  bool stop = 0;
  // Warning in case desired position is out of Canvas
  if ( (newY < 0.0) && (height < newY) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
    stop = 1;
  } else {
    if ((newY - position.y) < 0) {
      // Move in -Y direction
      motor2.step(1, FORWARD, SINGLE);
      motor1.step(1, BACKWARD, SINGLE);
    } else if ((newY - position.y) > 0) {
      // Move in +Y direction
      motor2.step(1, BACKWARD, SINGLE);
      motor1.step(1, FORWARD, SINGLE);
    }
    // Redefine pointer position after step
    position.y += 2 * resolution * copysign(1.0, (newY - position.y));
    if (abs(newY - position.y) < resolution) {
      stop = 1;
    }
    // Returns True when target position is reached
    return stop;
  }
}

bool Polargraph::square(float x, float y, float d) {
  // Bool variables to control position of pointer wrt target
  bool stop0 = 0;
  bool stop1 = 0;
  bool stop2 = 0;
  bool stop3 = 0;
  bool stop4 = 0;
  if (stop0 == 0) {
    stop0 = initPosition(x, y);
    Serial.println("stop0");
    Serial.println(stop0);
    Serial.println(position.x);
    Serial.println(position.y);
  } else if (stop1 == 0) {
    stop1 = moveInX(x + d);
    Serial.println("stop1");
    Serial.println(stop1);
  } else if (stop2 == 0) {
    stop2 = moveInY(y + d);
    Serial.println("stop2");
    Serial.println(stop2);
  } else if (stop3 == 0) {
    stop3 = moveInX(x);
    Serial.println("stop3");
    Serial.println(stop3);
  } else if (stop4 == 0) {
    stop4 = moveInY(y);
    Serial.println("stop4");
    Serial.println(stop4);
  }
  return stop4;
}

// Method for going back to default pointer position
bool Polargraph::restPosition() {
  return initPosition(0.0, 0.0);
}

// Method for returning current position in the grid
coordenates Polargraph::getPosition() {
  return position;
}
