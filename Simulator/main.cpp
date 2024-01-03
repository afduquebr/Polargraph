#include <iostream>
#include "simulator.h"
using namespace std;

float init_x = 0.0; // Define init position in x
float init_y = 0.0; // Define init position in y

int state = 0; // Stage in which pointer is moving
bool change = 0; // True if state must change

// Define Step Motors
Polargraph pointer(init_x, init_y);

int main() {
  // cout << "Hola, mundo!" << endl;

  float radius =  40.0;
  float displacement = 80.0;

  // cout << "Go to initial position! \n";

  while (state == 0) { 
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.initPosition(radius * cos(9 * M_PI / 10), -radius * sin(21 * M_PI / 10) + displacement);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We move to first vertex! \n";

  while (state == 1) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.move(radius * cos(21 * M_PI / 10), -radius * sin(21 * M_PI / 10) + displacement, true);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We move to second vertex! \n";

  while (state == 2) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.move(radius * cos(13 * M_PI / 10), -radius * sin(13 * M_PI / 10) + displacement, true);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We move to third vertex! \n";

  while (state == 3) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.move(radius * cos(M_PI / 2), -radius * sin(M_PI / 2) + displacement, true);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We move to fourth vertex! \n";

  while (state == 4) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.move(radius * cos(17 * M_PI / 10), -radius * sin(17 * M_PI / 10) + displacement, true);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We move to fifth vertex! \n";

  while (state == 5) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.move(radius * cos(9 * M_PI / 10), -radius * sin(21 * M_PI / 10) + displacement, true);
    if (change == 1) {
      state += 1;
    } 
  }

  // cout << "We go back to rest position! \n";

  while (state == 6) {
    cout << pointer.position.x << " " << pointer.position.y << "\n";  
    change = pointer.restPosition();
    if (change == 1) {
      state += 1;
    } 
  }

  return 0;
}



