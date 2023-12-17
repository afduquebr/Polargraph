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
  cout << "Hola, mundo!" << endl;

  cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  

  // cout << "Go to initial position! \n";

  // while (state == 0) {
  //   cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
  //   change = pointer.initPosition(0.0, 0.0);
  //   if (change == 1) {
  //     state += 1;
  //   } 
  // }

  // cout << "Now we do a square! \n";
  
  // int sq_state = 0;
  // while (state == 1) {
  //   change = pointer.square(0.0, 0.0, 70.0, sq_state);
  //   if (change == 1) {
  //     state += 1;
  //   } 
  //   cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
  // }

  // cout << "We go back to rest position! \n";

  // while (state == 2) {
  //   change = pointer.restPosition();
  //   if (change == 1) {
  //     state += 1;
  //   } 
  //   cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
  // }

  cout << "We move to a certain position! \n";

  while (state == 0) {
    change = pointer.move(0.0, 50.0, true);
    if (change == 1) {
      state += 1;
    } 
    cout << "x: " << pointer.position.x << " y: " << pointer.position.y << "\n";  
  }

  return 0;
}



