// Polargraph library
// Last Update: December 17th, 2023.
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
#include <Servo.h>


// Definition of technical properties of the machine
// All units are stated in mm

// Specs of the motors
static int steps = 200;
static float radius = 7.5; // Adjust to real radius

// Size of Canvas
static float width = 210.0;
static float height = 297.0;

// Initialization of motors
static AF_Stepper motor1(steps, 1);
static AF_Stepper motor2(steps, 2);
static Servo motor3;

// Position of the pointer
struct coordenates {
  float x;
  float y;
};

// Definition of the main class
class Polargraph {
  public:
    // Declaration of position coordenates from the pointer
    coordenates position;
    // Constructor of the class
    Polargraph(float x, float y);
    // Methods associated to the pointer
    void init(int speed, int pin); // Set speed
    bool initPosition(float x0, float y0); // Go to an initial point in the grid
    bool move(float newX, float newY, bool draw); //Move to any position
    bool moveInX(float newX, bool draw); // Move to a position in horizontal direction
    bool moveInY(float newY, bool draw); // Move to a position in vertical direction
    bool square(float x, float y, float d); // Do a square of size d
    bool restPosition(); // Go to default start position
    void raiseServo(); // Raise pencil from the canvas
    void lowerServo(); // Put pencil in drawing position
    coordenates getPosition(); // Return current position in the grid
  private:
    float resolution; // Resolution of movement 
    float limit = 0.253456; // Threshold for position
    bool fit = 1; // True if fit is required
    int st_square = 0; // States for drawing square
    float fit_parameters[3]; // Parameters from linear fit
    // Private methods for determining optimal displacement
    void linearFit(float x, float y); // Linear fit with respect to position
    float distance(float x1, float y1, float x2, float y2); // Distance between to points
    int minimum(float x, float y); // Determine minimum distance to point
};

#endif
