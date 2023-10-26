
#ifndef Polargraph_h
#define Polargraph_h

#include <math.h>
#include <stdio.h>
#include <Arduino.h>
#include <AFMotor.h>

static int steps = 200;
static float width = 15.0;
static float height = 30.0;
static float radius = 0.5;

static AF_Stepper motor1(steps, 1);
static AF_Stepper motor2(steps, 2);

struct coordenates {
  float x;
  float y;
};

enum State {
  UP,
  DOWN,
  RIGHT,
  LEFT,
  REST,
  INIT
};

class Polargraph {
  public:
    coordenates position;
    State state;
    Polargraph(float x, float y, State c);
    void speed(int v);
    void initPosition(float x0, float y0);
    void moveInX(float newX, State direction);
    void moveInY(float newY, State direction);
    void restPosition();
    coordenates getPosition();
  private:
    float resolution;

};

#endif
