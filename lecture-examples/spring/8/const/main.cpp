#include <iostream>
#include "demo.hpp"

using namespace std;

int main()
{
  demo       D(1,2,3); // non-const object
  demo const C(2,2,2); // const object

  cout << "Original D = " << D.get_abc() << endl;

  // can call non-const member function of non-const object
  D.set_demo(4,5,6);
  cout << "later D = " << D.get_abc() << endl;

  // can call const function of const object
  cout << "Original C = " << C.get_abc() << endl;

  // won't compile a non-const member function call on
  // on a const object
  C.set_demo(3,2,1);
  return 0;
}
