#include <AFMotor.h>
#include "polargraph.h"

float init_x; // Define init position in x
float init_y; // Define init position in y

State state = REST;

int steps = 200;

// Define Step Motors
Pointer pencil(init_x, init_y, state, steps);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Polargraph!");

  pencil.speed(10);  // 10 rpm
}

void loop() {
  // put your main code here, to run repeatedly:

}
