#include "circle.h"

circle::circle(float r){
  radius = r;
  cout << "circle with radius " << r << " was created" << endl;
}

float circle::area(void){
  circle_area = M_PI*radius*radius;
  return circle_area;
}
