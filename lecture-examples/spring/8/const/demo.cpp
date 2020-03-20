#include "demo.hpp"

// constructor
demo::demo(int i, int j, int k)
  :m(i) //member initializer syntax
{
  // call non-const member function
  set_demo(i, j, k);
}

void demo::set_demo(int i, int j, int k){
  // non-const member function
  a=i;
  b=j;
  c=k;
}

int demo::get_abc() const{
  // const member function
  return a*b*c;
}
