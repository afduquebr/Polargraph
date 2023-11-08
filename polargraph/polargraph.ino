#include "Polargraph.h"

float init_x = 0.0; // Define init position in x
float init_y = 0.0; // Define init position in y

int state = 0; // Stage in which pointer is moving
bool change = 0; // True if state must change

// Define Step Motors
Polargraph pointer(init_x, init_y);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Here we go!");

  pointer.speed(5); // 10 rpm
}

void loop() {
  /*
   *  Track Position of the pointer per step
   *    Serial.println(pointer.position.x);
   *    Serial.println(pointer.position.y);
   *    Serial.println(" ");
   */
  if (state == 0) {
    // First Stage
    // Go to initial Position (1.0,2.0)
    change = pointer.initPosition(1.0, 2.0);
    if (change == 1) {
      // Means pointer reached init Position
      state += 1;
    }
  } else if (state == 1) {
    // Second Stage
    // Move to 2.0 in X
    change = pointer.moveInX(2.0);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  } else if (state == 2) {
    // Third Stage
    // Move to 4.0 in Y
    change = pointer.moveInY(4.0);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  } else if (state == 3) {
    // Fourth Stage
    // Move to -1.0 in X
    change = pointer.moveInX(-1.0);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  } else if (state == 4) {
    // Fifth Stage
    // Move to 3.0 in Y
    change = pointer.moveInY(3.0);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  } else if (state == 5) {
    // Sixth Stage
    // Draw a square of size 7.0
    change = pointer.square(1.0, 4.0, 7.0);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  } else if (state == 6) {
    // Seventh Stage
    // Move to default position (0.0,0.0)
    change = pointer.restPosition();
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
      //Final Stage achieved
      Serial.println("Done!");
    }
  }
}
