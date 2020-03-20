#include <iostream>

using namespace std;

// compile with g++ -I. test-constr.cpp -o test-constr

// this test shows how constructors are called

class test1{
public:
  test1(){ // constructor
    cout << "C test1" << endl;
  }
};

class test2: public test1{
public:
  test2(): test1(){ // constructor, invoke the parent constructor
    cout << "C test2" << endl;
  }
};

int main(){
  cout << "creating an object invokes the constructors" << endl;
  test2 t2;
  cout << "so does the new operator" << endl;
  test2 * t2p = new test2();
  return 0;
}
