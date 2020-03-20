#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
// This enables the use of M_PI constant
#define _USE_MATH_DEFINES
#include <cmath>

class circle : public shape{
 private:
  float radius;
  float circle_area;
 public:
  circle(float r);
  float area(void);
};
#endif
