#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cmath>
#include "shape.hpp"

class circle;

class rectangle : public shape{
  // friend function declaration comes before access specifyer
  int friend inscribed(rectangle R, circle C);
 private:
  float upx,upy, lowx, lowy;
  float rect_area;
 public:
  rectangle(float ux, float uy, float lx, float ly);
  float area(void);
};

#endif
