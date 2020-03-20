#include <iostream>

using namespace std;

// compile with g++ -I. test-destr.cpp -o test-constr

// this test shows how destructors are called

class test1{
public:
  test1(){ // constructor
    cout << "C test1" << endl;
  }

  ~test1(){
    cout << "D test1" << endl;
  }
};

class test2: public test1{
public:
  test2(): test1(){ // constructor, invoke the parent constructor
    cout << "C test2" << endl;
  }

  ~test2(){
    cout << "D test2" << endl;
  }
};

int main(){
  cout << "creating an object invokes the constructors" << endl;
  test2 t2;

  cout << "so does the new operator" << endl;
  test2 * t2p = new test2();
  cout << "now freeing the object using delete" << endl;
  delete t2p; // free memory and destroy

  cout << "By leaving the scope of a function, the destructor is called" << endl;
  return 0;
}
