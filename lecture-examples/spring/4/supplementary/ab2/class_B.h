#ifndef B_H
#define B_H
#include <iostream>
#include "class_A.h"
using namespace std;

class B: public A{
 private:
  int m;
 public:
  B(void);
  ~B(void);
};
#endif // B_H
