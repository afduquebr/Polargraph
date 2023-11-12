// Polargraph library
// Last Update: November 12th, 2023.
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
  // Bool variable to control position of pointer wrt target
  bool stop = 0;
  // Move in Y and then in X
  if (abs(y0 - position.y) > resolution) {
    moveInY(y0);
  } else if (abs(x0 - position.x) > resolution) {
    moveInX(x0);
  } else {
    stop = 1;
  }
  // Returns True when movement in X is finished
  return stop;
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
    if (abs(newX - position.x) > resolution) {
      position.x += 2 * resolution * copysign(1.0, (newX - position.x));
    } else {
      stop = 1;
    }
    // Returns True when target position is reached
  }
  return stop;
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
    if (abs(newY - position.y) > resolution) {
      position.y += 2 * resolution * copysign(1.0, (newY - position.y));
    } else {
      stop = 1;
    }
    // Returns True when target position is reached
  }
  return stop;
}

// Method for drawing a square
bool Polargraph::square(float x, float y, float d, int& state) {
  // Bool variables to control position of pointer wrt target
  bool change, stop;
  if (state == 0) {
    // Get to right top of the square
    change = initPosition(x, y);
    if (change == 1) state += 1;
  } else if (state == 1) {
    // Draw upper horizontal line
    change = moveInX(x + d);
    if (change == 1) state += 1;
  } else if (state == 2) {
    // Draw right vertical line
    change = moveInY(y + d);
    if (change == 1) state += 1;
  } else if (state == 3) {
    // Draw lower horizontal line
    change = moveInX(x);
    if (change == 1) state += 1;
  } else {
    // Draw left vertical line
    stop = moveInY(y);
  }
  return stop;
}

// Method for going back to default pointer position
bool Polargraph::restPosition() {
  return initPosition(0.0, 0.0);
}

// Method for returning current position in the grid
coordenates Polargraph::getPosition() {
  return position;
}
