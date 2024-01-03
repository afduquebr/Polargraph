// Polargraph library
// Last Update: December 17th, 2023.
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

// Set speed for the displacement and precise servo pin
void Polargraph::init(int speed, int pin) {
  // Set same speed for both engines
  // v is set in rpm
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  // Declare pin to which servo motor is connected
  motor3.attach(pin);
} 

// Method for getting to a certain initial point in the grid
bool Polargraph::initPosition(float x0, float y0) {
  // Bool variable to control position of pointer wrt target
  bool stop = 0;
  // Move in Y and then in X
  if (abs(y0 - position.y) > resolution) {
    moveInY(y0, false);
  } else if (abs(x0 - position.x) > resolution) {
    moveInX(x0, false);
  } else {
    stop = 1;
  }
  // Returns True when movement in X is finished
  return stop;
}

// Method for getting to a certain point in the grid
bool Polargraph::move(float newX, float newY, bool draw){
  // Bool variable to control position of pointer wrt target
  bool stop = 0;
  // Warning in case desired position is out of Canvas
  if ( (newX < - (width / 2)) || ((width / 2) < newX) || (newY < 0.0) || (height < newY) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
    stop = 1;
  } else {
    // Move to closest position from target diagonally 
    if (abs(newX - position.x) + abs(newY - position.y) >= limit) {
      if (draw == 1) lowerServo(); // Lower pointer if draw is True
      int min = minimum(newX, newY); // Determine closest position to move 
      if (min == 0) { // Move one step to the left and up
        motor1.step(1, BACKWARD, SINGLE);
        // Update position after moving
        position.x -= resolution;
        position.y -= resolution;
      } else if (min == 1) { // Move one step to the right and up
        motor2.step(1, FORWARD, SINGLE);
        // Update position after moving
        position.x += resolution;
        position.y -= resolution;
      } else if (min == 2) { // Move one step to the right and down
        motor1.step(1, FORWARD, SINGLE);
        // Update position after moving
        position.x += resolution;
        position.y += resolution;
      } else if (min == 3) { // Move one step to the left and down
        motor2.step(1, BACKWARD, SINGLE);
        // Update position after moving
        position.x -= resolution;
        position.y += resolution;
      } 
      stop = 0;
    } else {
      // Raise pointer after finishing if draw is True
      raiseServo();
      // Restore variable for doing linear fit after finishing
      fit = 1;
      stop = 1;
    }
  }
  // Returns True when movement is finished
  return stop;
}

// Method for horizontal displacement
bool Polargraph::moveInX(float newX, bool draw) {
  // Bool variables to control x position of pointer wrt target
  bool stop = 0;
  // Warning in case desired position is out of Canvas
  if ( (newX < - (width / 2)) || ((width / 2) < newX) ) {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
      stop = 1;
  } else {
    // Lower pointer for drawing if true
    if (draw == 1) lowerServo();
    // Check direction of motion
    if ((newX - position.x) > 0) {
      // Move in +X direction
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    } else if ((newX - position.x) < 0) {
      // Move in -X direction
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    // Update pointer position after step
    if (abs(newX - position.x) > resolution) {
      position.x += 2 * resolution * copysign(1.0, (newX - position.x));
    } else {
      // Raise pointer after finishing if draw is True
      raiseServo();
      stop = 1;
    }
    // Returns True when target position is reached
  }
  return stop;
}

// Method for vertical displacement
bool Polargraph::moveInY(float newY, bool draw) {
  // Bool variables to control y position of pointer wrt target
  bool stop = 0;
  // Warning in case desired position is out of Canvas
  if ( (newY < 0.0) || (height < newY) )  {
    Serial.println(" FATAL ERROR: Pointer position outside of Canvas");
    stop = 1;
  } else {
    // Lower pointer for drawing if true
    if (draw == 1) lowerServo();
    // Check direction of motion
    if ((newY - position.y) < 0) {
      // Move in -Y direction
      motor2.step(1, FORWARD, SINGLE);
      motor1.step(1, BACKWARD, SINGLE);
    } else if ((newY - position.y) > 0) {
      // Move in +Y direction
      motor2.step(1, BACKWARD, SINGLE);
      motor1.step(1, FORWARD, SINGLE);
    }
    // Update pointer position after step
    if (abs(newY - position.y) > resolution) {
      position.y += 2 * resolution * copysign(1.0, (newY - position.y));
    } else {
      // Raise pointer after finishing if draw is True
      raiseServo();
      stop = 1;
    }
  }
  // Returns True when target position is reached
  return stop;
}

// Method for drawing a square
bool Polargraph::square(float x, float y, float d) {
  // Bool variables to control position of pointer wrt target
  bool change = 0, stop = 0;
  if (st_square == 0) {
    // Get to right top of the square
    change = initPosition(x, y);
    if (change == 1) st_square += 1;
  } else if (st_square == 1) {
    // Draw upper horizontal line
    change = moveInX(x + d, true);
    if (change == 1) st_square += 1;
  } else if (st_square == 2) {
    // Draw right vertical line
    change = moveInY(y + d, true);
    if (change == 1) st_square += 1;
  } else if (st_square == 3) {
    // Draw lower horizontal line
    change = moveInX(x, true);
    if (change == 1) st_square += 1;
  } else {
    // Draw left vertical line
    stop = moveInY(y, true);
    if (stop == 1) {
      st_square = 0;
    }
  }
  // Returns True when square is finished
  return stop;
}

// Method for going back to default pointer position
bool Polargraph::restPosition() {
  return initPosition(0.0, 0.0);
}

// Method for raising the pointer from the canvas
void Polargraph::raiseServo() {
  motor3.write(90); 
}

// Method for lowering the pointer from the canvas
void Polargraph::lowerServo() {
  motor3.write(180);
}

// Method for returning current position in the grid
coordenates Polargraph::getPosition() {
  return position;
}

// Method for determining linear fit parameters
void Polargraph::linearFit(float x, float y){
  if (abs(y - position.y) <= abs(x - position.x)) {
    // Fit if slope is less or equal to 1 y(x)
    // Determine slope 
    fit_parameters[0] = (y - position.y) / (x - position.x);
    // Determine y intercept
    fit_parameters[1] = y - fit_parameters[0] * x;
    // Parameter to know that fit is y(x)
    fit_parameters[2] = 0;
  } else {
    // Fit if slope is bigger than 1 y(x)
    // Determine slope 
    fit_parameters[0] = (x - position.x) / (y - position.y);
    // Determine x intercept
    fit_parameters[1] = x - fit_parameters[0] * y;
    // Parameter to know that fit is x(y)
    fit_parameters[2] = 1;
  }
}

// Method for determining Euclidean distance between two points
float Polargraph::distance(float x1, float y1, float x2, float y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Determine minimum distance between two points
int Polargraph::minimum(float x, float y) {
  float diagonal[4]; // Stores distance wrt the diagonal
  if (fit == 1) {
    // Perform linear fit between initial position and target
    linearFit(x, y);
    fit = 0;
  }
  if (fit_parameters[2] == 0) { // Determine distance to diagonal if fit if y(x)
    // Distance to diagonal if moving one step up and left
    diagonal[0] = distance(0, position.y - resolution, 0, fit_parameters[0] * (position.x - resolution) + fit_parameters[1]);
    // Distance to diagonal if moving one step up and right
    diagonal[1] = distance(0, position.y - resolution, 0, fit_parameters[0] * (position.x + resolution) + fit_parameters[1]);
    // Distance to diagonal if moving one step down and right
    diagonal[2] = distance(0, position.y + resolution, 0, fit_parameters[0] * (position.x + resolution) + fit_parameters[1]);
    // Distance to diagonal if moving one step down and left
    diagonal[3] = distance(0, position.y + resolution, 0, fit_parameters[0] * (position.x - resolution) + fit_parameters[1]);
  } else { // Determine distance to diagonal if fit if x(y)
    // Distance to diagonal if moving one step up and left
    diagonal[0] = distance(position.x - resolution, 0, fit_parameters[0] * (position.y - resolution) + fit_parameters[1], 0);
    // Distance to diagonal if moving one step up and right
    diagonal[1] = distance(position.x + resolution, 0, fit_parameters[0] * (position.y - resolution) + fit_parameters[1], 0);
    // Distance to diagonal if moving one step down and right
    diagonal[2] = distance(position.x + resolution, 0, fit_parameters[0] * (position.y + resolution) + fit_parameters[1], 0);
    // Distance to diagonal if moving one step down and left
    diagonal[3] = distance(position.x - resolution, 0, fit_parameters[0] * (position.y + resolution) + fit_parameters[1], 0);
  }

  // Determine distance between actual position and target
  float dist[4] = {
        // Distance to target if moving one step up and left
        distance(position.x - resolution, position.y - resolution, x, y),
        // Distance to target if moving one step up and right
        distance(position.x + resolution, position.y - resolution, x, y),
        // Distance to target if moving one step down and right
        distance(position.x + resolution, position.y + resolution, x, y),
        // Distance to target if moving one step down and left
        distance(position.x - resolution, position.y + resolution, x, y),
  };
  // Determine two minimum distances
  int min = 0, min1 = 0, min2 = 1;
  if (dist[min1] > dist[1]) {
    min2 = min1;
    min1 = 1;
  }
  if (dist[min1] > dist[2]) {
    min2 = min1;
    min1 = 2; 
  } else if (dist[min2] > dist[2]) {
    min2 = 2;
  }
  if (dist[min1] > dist[3]) {
    min2 = min1;
    min1 = 3;
  } else if (dist[min2] > dist[3]) {
    min2 = 3;
  }
  // Determine closest point to the diagonal between minimum distances
  if(diagonal[min1] < diagonal[min2]) {
    min = min1;
  } else {
    min = min2;
  }
  // Return minimum distance to the target and to the diagonal
  return min;
}