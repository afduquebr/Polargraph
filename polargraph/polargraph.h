
#ifndef Polargraph_h
#define Polargraph_h

#include <math.h>
#include <stdio.h>
#include <Arduino.h>
#include <AFMotor.h>

static int steps = 200;
static float width = 210.0;
static float height = 297.0;
static float radius = 5;

static AF_Stepper motor1(steps, 1);
static AF_Stepper motor2(steps, 2);

struct coordenates {
  float x;
  float y;
};

enum State {
  Y,
  X,
  REST,
  INIT
};

class Polargraph {
  public:
    coordenates position;
    Polargraph(float x, float y);
    void speed(int v);
    bool initPosition(float x0, float y0);
    bool moveInX(float newX);
    bool moveInY(float newY);
    bool restPosition();
    coordenates getPosition();
  private:
    float resolution;
};

#endif
