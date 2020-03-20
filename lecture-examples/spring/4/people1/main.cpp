#include <iostream>
#include <person.hpp>

using namespace std;

// compile with g++ -I. *.cpp -o main

int main(){
  person boss;
  boss.setName("my Boss");
  boss.setHairColor(COLOR_BLACK);
  boss.print();

  return 0;
}
