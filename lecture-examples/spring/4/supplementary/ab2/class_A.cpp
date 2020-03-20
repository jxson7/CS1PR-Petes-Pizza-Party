#include "class_A.h"

A::A(void){
  k = 1;
  cout << "Class A. Initial value of k = " << k << endl;
}
A::~A(void){
  k = 0;
  cout << "Class A. Final value of k = " << k << endl;
}
