#include <iostream>
using namespace std;

template <typename T>
T maximum(T x, T y){
  T m;
  if (x < y)
       m = y;
     else
       m = x;
  return m;
}

int main(){
  cout << maximum('a','A') << endl;
  cout << maximum(1.23, 3.4) << endl;
  return 0;
}
