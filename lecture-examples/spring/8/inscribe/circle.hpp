#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"
// This enables the use of M_PI constant
#define _USE_MATH_DEFINES
#include <cmath>

class rectangle;

class circle : public shape{
  // friend function declaration comes before access specifyer
  int friend inscribed(rectangle R, circle C);
 private:
  float radius, cx, cy;
  float circle_area;
 public:
  circle(float r, float x, float y);
  float area(void);
};
#endif
