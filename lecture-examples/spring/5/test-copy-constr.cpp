
#include <iostream>

using namespace std;

// compile with g++ -I. test-constr.cpp -o test-constr

// this test shows how the copy constructor is called

class test1{
public:
  test1(){ // constructor
    cout << "C test1" << endl;
  }

  test1(const test1 &o){ // copy constructor
    cout << "CC test1" << endl;
  }

  ~test1(){ // be aware that virtual should be used!
    cout << "D test1" << endl;
  }
};

class test2: public test1{
public:
  test2(): test1(){ // constructor, invoke the parent constructor
    cout << "C test2" << endl;
  }

  test2(const test2 &o) : test1(o){ // copy constructor, important to invoke parent CC!
    cout << "CC test2" << endl;
  }

  ~test2(){
    cout << "D test2" << endl;
  }
};

void callmeByValueTest1(test1 t){

}

void callmeByValueTest2(test2 t){

}

void callmeByReferenceTest1(test1 & t){

}

void callmeByReferencePointerTest1(test1 * t){

}

int main(){
  cout << "creating an object invokes the constructors" << endl;
  test2 t2;

  cout << "calling callmeByValueTest1(test1 t) with t2" << endl;
  callmeByValueTest1(t2);

  cout << "calling callmeByValueTest2(test2 t) with t2" << endl;
  callmeByValueTest2(t2);

  cout << "calling callmeByReferenceTest1(test1 & t) with t2" << endl;
  callmeByReferenceTest1(t2);

  cout << "calling callmeByReferencePointerTest1(test1 * t) with t2" << endl;
  callmeByReferencePointerTest1(& t2);

  cout << "End of main()" << endl;
  return 0;
}
