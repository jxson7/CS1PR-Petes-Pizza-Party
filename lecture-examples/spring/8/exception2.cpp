#include <iostream>

using namespace std;

void func(int i){
  cout << "Calling func with " << i << endl;
  // i should be < 10
  if(i >= 10){
    throw out_of_range("TestError");
  }
}

void func1(){
  func(1);
  func(10);
}

int main(int argc, char ** argv){
  try{
    func1();
  }catch(out_of_range & a){
    // it might return an out_of_range error
    // we may want to deal with it gracefully
    cout << "Warning out of range error" << endl;
  }catch(exception & b){
    // catch any other exception
    // abort the program
    throw b;
  }

  return 0;
}
