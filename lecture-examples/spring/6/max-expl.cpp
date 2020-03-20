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

// specialization for the bool datatype
template <>
bool maximum<bool>(bool a, bool b) {
    return a || b;
}

// explicit instantiation of the maximum function for char
template char maximum<>(char, char);

int main(){
  // decide upon the template argument upon call time
  cout << maximum<char>('a','A') << endl;
  cout << maximum<int>(1.23, 3.4) << endl;
  // actually needed in this case:
  cout << maximum<double>(2, 3.4) << endl;
  return 0;
}
