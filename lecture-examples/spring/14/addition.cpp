#include <iostream>
#include <string>
#include <sstream>

#include <assert.h>

using namespace std;

template <typename T>
T addition(T x1, T x2){
  return x1 + x2;
}

int main(){
  assert(addition(3, 2) == 5);
  assert(addition(3.0, 2.0) == 5.0);
  return 0;
}
