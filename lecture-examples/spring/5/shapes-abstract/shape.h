#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class shape{
public:
  virtual float area(void) = 0;
  virtual ~shape(){}; // virtual destructor
};
#endif
