#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template< int a, int b > struct GCD {
    static const int RESULT = GCD< b, a % b >::RESULT;
};

template< int a > struct GCD< a, 0 > {
    static const int RESULT = a;
};

GCD<25, 50> var;

int main() {
  cout << "GCD (25,50) == " << GCD<25, 50>::RESULT << endl;
  cout << "GCD (12,64) == " << GCD<12, 64>::RESULT << endl;
  cout << "GCD (a,b) == " << GCD<18, 8398176>::RESULT << endl;

  return 0;
}
