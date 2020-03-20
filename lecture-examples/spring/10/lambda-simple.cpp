#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//This example may only work with recent compilers.
//clang++-9 -stdlib=libc++ lambda-simple.cpp

int main() {
  std::function<string()> funct = []() { return "Hello"; };
  cout << funct() << endl;

  auto ifunct = []() { return 5; };
  cout << ifunct() << endl;


  int multiplier = 2;
  auto ifunct2 = [&multiplier](int v) { return v * multiplier; };
  cout << ifunct2(6) << endl;
}
