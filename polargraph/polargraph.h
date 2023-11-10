// Polargraph library
// Last Update: November 8th, 2023.
// Andrés Felipe Duque Bran

/*
 * Usage Notes:
 *
 * 1) This code is designed for operating two bipolar stepper motors at the
 *    same time in order to move a pointer, which is attached symmetrically to
 *    both engines, over a 2D grid. (Polargraph)
 *
 * 2) The resolution of movement of this pointer is constrained by the
 *    technical design of the device.
 *
 * 3) This library controls the stepper motors by employing the "Adafruit Motor
 *    shield library". Therefore, its installation is compulsory in order to use
 *    it.
 *
 */


#ifndef Polargraph_h
#define Polargraph_h

#include <math.h>
#include <stdio.h>
#include <Arduino.h>
#include <AFMotor.h>

// Definition of technical properties of the machine
// All measures are stated in mm

// Specs of the motors
static int steps = 200;
static float radius = 10;

// Size of Canvas
static float width = 210.0;
static float height = 297.0;

// Initialization of the motors
static AF_Stepper motor1(steps, 1);
static AF_Stepper motor2(steps, 2);

// Position of the pointer
struct coordenates {
  float x;
  float y;
};

/* State of motion from the pointer
 * Currently not in use
 *    enum State {
 *      Y,
 *      X,
 *      REST,
 *      INIT
 *    };
 */

// Definition of the main class
class Polargraph {
  public:
    // Declaration of position coordenates from the pointer
    coordenates position;
    // Constructor of the class
    Polargraph(float x, float y);
    // Methods associated to the pointer
    void speed(int v); // Set speed
    bool initPosition(float x0, float y0); // Go to an initial point in the grid
    bool moveInX(float newX); // Move to a position in horizontal direction
    bool moveInY(float newY); // Move to a position in vertical direction
    bool square(float x, float y, float d); // Do a square of size d
    bool restPosition(); // Go to default start position
    coordenates getPosition(); // Return current position in the grid
  private:
    // Declaration of minimum step resolution for the pointer
    float resolution;
};

#endif
