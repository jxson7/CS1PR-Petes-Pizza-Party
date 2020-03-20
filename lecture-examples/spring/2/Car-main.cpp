#include <iostream>
#include <Car.hpp>

using namespace std;

int main() {
   Car car1; // creates a new instance
   car1.setColour("blue");
   Car car2; // creates a new instance
   car2. setColour("red");
   cout << "car1 color is: " << car1.colour << endl;

   Car * car1p;
   car1p  = new Car(); // instantiating a new car using new operator
   car1p->setColour("blue");
   cout << "car1 color is: " << car1p->colour << endl;
   delete car1p; // freeing car

  return 0;
}
