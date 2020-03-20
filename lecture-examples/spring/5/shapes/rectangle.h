#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class rectangle : public shape{
 private:
  float a, b;
  float rect_area;
 public:
  rectangle(float m, float n);
  float area(void);
};

#endif
