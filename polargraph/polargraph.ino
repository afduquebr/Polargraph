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
  delay(1000);

}

void loop() {
  /*
   *  Track Position of the pointer per step
   *    Serial.println(pointer.position.x);
   *    Serial.println(pointer.position.y);
   *    Serial.println(" ");
   */
  // Serial.println(pointer.position.x);
  // Serial.println(pointer.position.y);
  // Serial.println(" ");
  //=pointer.position.x;
  //float b=pointer.position.y;
  //Serial.println(state);
  //Serial.println("qwe");
  // delay(1000);
  if (state == 0) 
  {
    pointer.lowerServo();
    // First Stage
    // Go to initial Position (50.0,5.0)
    // Serial.println("before");
    // change = pointer.initPosition(0.0, 0.0);
    // Serial.println(change);
    // if (change == 1) {
    //   // Means pointer reached init Position
    //   state += 1;
    }
  // } else if (state == 1) 
  // {
  //   // Second Stage
  //   // Move to 100.0 in X
  //   pointer.lowerServo();
  //   change = pointer.moveInX(100.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } else if (state == 1) 
  // {
  //   // Third Stage
  //   // Move to 200.0 in Y
  //   change = pointer.moveInX(-100.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     pointer.raiseServo();
  //     state += 1;
  //   }
  // } else if (state == 2) 
  // {
  //   // Fourth Stage
  //   // Move to -50.0 in X
  //   change = pointer.moveInY(100.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } else if (state == 3) 
  // {
  //   // Fifth Stage
  //   // Move to 50.0 in Y
  //   pointer.lowerServo();
  //   change = pointer.moveInX(100.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     pointer.raiseServo();
  //     state += 1;
  //   }
  // } else if (state == 4) 
  // {
  //   // Sixth Stage
  //   // Draw a square of size 50.0
  //   change = pointer.moveInY(200.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } else if (state == 5) 
  // {
  //   // Seventh Stage
  //   // Move to default position (0.0,0.0)
  //   pointer.lowerServo();
  //   change = pointer.moveInX(-100.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     pointer.raiseServo();
  //     state += 1;
  //     //Final Stage achieved
  //     Serial.println("Done!");
  //   }
  // }
}
