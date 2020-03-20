#ifndef B_H
#define B_H
#include "class_A.h"

class B: public A{
 private:
  int k;
 public:
  void set_k(void);
  int get_k(void);
  void show(void);
};
#endif // B_H

