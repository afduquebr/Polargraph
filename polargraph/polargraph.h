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
  REST,
  INIT
};

static coordenates rest = { }

class Pointer {
  public:
    coordenates position;
    State state;
    Pointer(float x, float y, State c, int steps);
    void speed(int v);
    void initPosition(float x0, float y0);
    void moveInX(float newX, State direction);
    void moveInY(float newY, State direction);
    void restPosition();
    coordenates getPosition();
  private:
    // Dimensions of the Canvas
    // DEFINE BEFORE EXECUTION
    float width;
    float height;
    float resolution;
    engines motors;

}
