#ifndef A_H
#define A_H
#include <iostream>
using namespace std;

class A{
 protected:
  int i,j;
 public:
  void set_ij(int m, int n);
  void out_ij(void);
};
#endif // A_H

