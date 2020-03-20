#include <iostream>
#include <string>
#include <sstream>

#include <assert.h>

using namespace std;

bool isAutomorphic(int num);

int main(){
  assert(isAutomorphic(5) == true);
  assert(isAutomorphic(8) == false);
  assert(isAutomorphic(76) == true);
  return 0;
}
