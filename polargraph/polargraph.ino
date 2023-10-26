#include "Polargraph.h"

float init_x; // Define init position in x
float init_y; // Define init position in y

int state = 0;

// Define Step Motors
Polargraph pointer(init_x, init_y);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Polargraph!");

  pointer.speed(10);  // 10 rpm
}

void loop() {
  bool change;
  if (state == 0) {
    change = pointer.initPosition(40.0, 40.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 1) {
    change = pointer.moveInX(100.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 2) {
    change = pointer.moveInY(80.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 3) {
    change = pointer.moveInX(-150.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 4) {
    change = pointer.moveInY(-60.0);
    if (change == 1) {
      state += 1;
    }
  }
}
