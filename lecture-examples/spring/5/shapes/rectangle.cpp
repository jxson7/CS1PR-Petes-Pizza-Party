#include "rectangle.h"

rectangle::rectangle(float m, float n){
  a = m;
  b = n;
  cout << "rectangle with sides " << a << "and "
       << b << " was created" << endl;
}

float rectangle::area(void){
  rect_area = a*b;
  return rect_area;
}
