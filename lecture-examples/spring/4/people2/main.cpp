#include <iostream>
#include <person.hpp>

using namespace std;

// compile with g++ -I. *.cpp -o main

int main(){
  person boss("my Boss", COLOR_BLACK);
  boss.print();
  boss.dyeHair(COLOR_BLUE);
  boss.print();

  person jane;
  jane.print();

  return 0;
}
