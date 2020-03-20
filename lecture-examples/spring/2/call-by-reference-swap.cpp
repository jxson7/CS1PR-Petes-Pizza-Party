#include <iostream>

using namespace std;

// Remember the swap function in C using pointers?
// Here is the C++ equivalent

void swap (int & first, int & second){
	int temp;
	temp = first;
	first = second;
	second = temp;
}

int main(){
	int a = 5;
	int b = 3;
	swap(a, b);
	// what is a, b after the call?
  cout << "a = " << a << endl << "b = " << b << endl;
	return 0;
}
