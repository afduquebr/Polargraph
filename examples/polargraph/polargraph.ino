#include <Polargraph.h>

float init_x = 0.0; // Define initial position in x
float init_y = 0.0; // Define initial position in y

int state = 0; // State in which pointer is moving
bool change = 0; // True if state must change

// Define Variables for drawing a star
static float r =  40.0, d = 80.0;

// Define Step and Servo Motors
Polargraph pointer(init_x, init_y);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Here we go!");

  pointer.init(5, 10); // 5 rpm, pin #10
  delay(1000);

}

void loop() {
  /*
   *  Track position of the pointer per step
   *    Serial.println(pointer.position.x);
   *    Serial.println(pointer.position.y);
   *    Serial.println(" ");
   */
  if (state == 0) 
  {
    pointer.raiseServo();
    // First Stage
    
    // Go to initial Position 
    change = pointer.initPosition(r * cos(9 * M_PI / 10), -r * sin(21 * M_PI / 10) + d);
    if (change == 1) {
      // Means pointer has reached init Position
      state += 1;
    }
  } else if (state == 1) {
    // Second Stage
    // Move to first vertex
    change = pointer.move(r * cos(21 * M_PI / 10), -r * sin(21 * M_PI / 10) + d, true);
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
    }
  } else if (state == 2) {
    // Third Stage
    // Move to second vertex
    change = pointer.move(r * cos(13 * M_PI / 10), -r * sin(13 * M_PI / 10) + d, true);
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
    }
  } else if (state == 3) {
    // Fourth Stage
    // Move to third vertex
    change = pointer.move(r * cos(M_PI / 2), -r * sin(M_PI / 2) + d, true);
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
    }
  } else if (state == 4) {
    // Fifth Stage
    // Move to fourth vertex
    change = pointer.move(r * cos(17 * M_PI / 10), -r * sin(17 * M_PI / 10) + d, true);
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
    }
  } else if (state == 5) {
    // Sixth Stage
    // Move to fifth vertex
    change = pointer.move(r * cos(9 * M_PI / 10), -r * sin(21 * M_PI / 10) + d, true);
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
    }
  } else if (state == 6) 
  {
    // Seventh Stage
    // Move to default position
    change = pointer.restPosition();
    if (change == 1) {
      // Means pointer has reached desired position
      state += 1;
      //Final Stage achieved
      Serial.println("Done!");
    }
  }
} 