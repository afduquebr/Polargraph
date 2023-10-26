#include "Polargraph.h"

float init_x; // Define init position in x
float init_y; // Define init position in y

State state = REST;

// Define Step Motors
Polargraph pointer(init_x, init_y, state);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Polargraph!");

  pointer.speed(10);  // 10 rpm
}

void loop() {
  // put your main code here, to run repeatedly:
  pointer.moveInX(5.0, LEFT);
}
