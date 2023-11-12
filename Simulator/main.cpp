#include <iostream>
#include "simulator.h"
using namespace std;

float init_x = 50.0; // Define init position in x
float init_y = 50.0; // Define init position in y

int state = 0; // Stage in which pointer is moving
bool change = 0; // True if state must change

// Define Step Motors
Polargraph pointer(init_x, init_y);

int main() {
  cout << "Hola, mundo!" << endl;

  cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  

  while (state == 0) {
    cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
    change = pointer.moveInX(50.20);
    if (change == 1) {
      state += 1;
    } 
  }

  cout << " Now we do a square! \n";
  
  int sq_state = 0;
  while (state == 1) {
    change = pointer.square(55.0, 55.0, 5.0, sq_state);
    if (change == 1) {
      state += 1;
    } 
    cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
  }

  return 0;
}

