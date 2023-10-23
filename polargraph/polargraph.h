#include <AFMotor.h>



struct coordenates {
  float x;
  float y;
};

struct engines {
  AF_Stepper m1;
  AF_Stepper m2;
}

enum State {
  UP,
  DOWN,
  RIGHT,
  LEFT,
  REST
};

static coordenates rest = { }

class Pointer {
  public:
    coordenates position;
    State state;
    engines motors;
    Pointer(float x, float y, State c, int steps);
    void speed(int v);
    void initPosition(coordenates desired position);
    void moveInX();
    void moveInY();
    void restPosition();
    void getPosition();
}
