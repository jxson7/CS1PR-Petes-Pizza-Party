#include <iostream>
using namespace std;

template<typename T> constexpr T pi = T(3.141592653589793238462643383L);

int main(){
  cout << pi<int> << endl;
  cout << pi<float> << endl;
  return 0;
}
