#include "circle.hpp"

circle::circle(float r, float x, float y){
  radius = r;
  cx = x;
  cy = y;
  cout << "circle with radius " << r << " was created" << endl;
}

float circle::area(void){
  circle_area = M_PI*radius*radius;
  return circle_area;
}
