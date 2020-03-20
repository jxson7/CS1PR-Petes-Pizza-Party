#include "class_C.h" // class's header file

void C::f(int m, int n){
  i = m*m;
  j = n*n;
}
void C::show(){
  cout << "i of c object = " << i << "\nj of c object = " << j << endl;
}
