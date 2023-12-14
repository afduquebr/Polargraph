#include "Polargraph.h"

float init_x = 0.0; // Define init position in x
float init_y = 0.0; // Define init position in y

int state = 0; // Stage in which pointer is moving
int sq_state = 0; // Stage in which pointer is moving during the square
bool change = 0; // True if state must change

// Temp variables for deterimning the erratic movement
int countx1 = 0;
int county1 = 0;
int countx2 = 0;
int county2 = 0;

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
  // {
    // First Stage
    // Go to initial Position (50.0,5.0)
    // Serial.println("before");
    // change = pointer.initPosition(0.0, 0.0);
    // Serial.println(change);
    // if (change == 1) {
    //   // Means pointer reached init Position
    //   state += 1;
    // }
  // } else if (state == 1) 
  {
    // Second Stage
    // Move to 100.0 in X
    change = pointer.move(70.0, 60.0, true);
    if (change == 1) {
      // Means pointer reached desired position
      state += 1;
    }
  // } else if (state == 1) 
  // {
  //   // Third Stage
  //   // Move to 200.0 in Y
  //   change = pointer.moveInX(20.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } else if (state == 2) 
  // {
  //   // Fourth Stage
  //   // Move to -50.0 in X
  //   change = pointer.moveInY(20.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } else if (state == 3) 
  // {
  //   // Fifth Stage
  //   // Move to 50.0 in Y
  //   change = pointer.moveInX(0.0);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } //else if (state == 5) 
  // {
  //   // Sixth Stage
  //   // Draw a square of size 50.0
  //   change = pointer.square(0.0, 0.0, 70.0, sq_state);
  //   Serial.print("x=");
  //   Serial.println(pointer.position.x);
  //   Serial.print("y=");
  //   Serial.println(pointer.position.y);
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //   }
  // } //else if (state == 6) 
  // {
  //   // Seventh Stage
  //   // Move to default position (0.0,0.0)
  //   pointer.raiseServo();
  //   change = pointer.restPosition();
  //   if (change == 1) {
  //     // Means pointer reached desired position
  //     state += 1;
  //     //Final Stage achieved
  //     Serial.println("Done!");
  //   }
  // }
}
