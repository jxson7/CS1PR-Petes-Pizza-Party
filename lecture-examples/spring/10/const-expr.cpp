#include <iostream>

using namespace std;

constexpr int varX = 10;

constexpr int get_five() {
  return varX/2;
}

int main(){
  int some_value[get_five() + 7]; // Create an array of 12 integers
  return 0;
}
