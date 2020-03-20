#include <iostream>
#include <person.hpp>

using namespace std;

// compile with g++ -I. *.cpp -o main

void callPersonPrint(person & p){
  p.print();
}

int main(){
  student max("Max Mustermann", 4712, COLOR_GREEN, 83000303);

  // testing polymorphism again:
  person test = max;
  cout << "We assigned a student to a person and print it. This will call the person print() function as a student is a person." << endl;
  test.print();

  cout << "When we use a function with call by value to print the person" << endl;
  callPersonPrint(test);

  cout << "We call the print function using call by reference. This will use our virtual function." << endl;
  callPersonPrint(max);

  // we can directly create a reference using a variable
  person & p = max;
  p.print();
  cout << "Using RTTI to retrieve the type of p: " << typeid(p).name() << endl;

  return 0;
}
