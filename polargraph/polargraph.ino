#include "Polargraph.h"

float init_x = 0.0; // Define init position in x
float init_y = 7.0; // Define init position in y

int state = 0;
bool change = 0;

// Define Step Motors
Polargraph pointer(init_x, init_y);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Polargraph!");

  pointer.speed(5);  // 10 rpm
}

void loop() {
  Serial.println(pointer.position.x);
  Serial.println(pointer.position.y);
  Serial.println(" ");
  if (state == 0) {
    change = pointer.moveInY(4.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 1) {
    delay(500);
    change = pointer.moveInX(2.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 2) {
    delay(500);
    change = pointer.moveInY(4.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 3) {
    delay(500);
    change = pointer.moveInX(-1.0);
    if (change == 1) {
      state += 1;
    }
  } else if (state == 4) {
    delay(500);
    change = pointer.moveInY(0.0);
    if (change == 1) {
      state += 1;
      Serial.println("Done!");
    }
  }
}
