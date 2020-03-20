#include <iostream>
#include <person.hpp>

using namespace std;

// compile with g++ -I. *.cpp -o main

int main(){
  person boss("My Boss", 4711, COLOR_BLACK);
  boss.print();
  boss.dyeHair(COLOR_BLUE);
  boss.print();

  student max("Max Mustermann", 4712, COLOR_GREEN, 83000303);
  max.print();

  boss = max;
  boss.print();

  return 0;
}
