#include <iostream>

using namespace std;

int main(int argc, char ** argv){

  try{
    // do something that may throw an exception
    throw out_of_range("TestError");
  }catch(out_of_range & a){
    // it might return an out_of_range error
    // we may want to deal with it gracefully
    cout << "Warning out of range error" << endl;
  }catch(exception & b){
    // catch any other exception
    // abort the program
    cout << "Error: " << b.what() << endl;
    throw b;
  }

  return 0;
}
