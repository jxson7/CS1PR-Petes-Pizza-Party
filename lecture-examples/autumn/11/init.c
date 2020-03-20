#include <stdio.h>

// a benefit of using an array is that we know the number of elements
int worker5(int x[2], char * str){
	x[1] = 4; // equivalent to *(x+1) = 4
  printf("worker5 %d - %s\n", x[1], str);
  return 0;
}

// an issue when using a pointer is that we do not know what it is
int worker6(int * x, char * str){
	x[1] = 4; // equivalent to *(x+1) = 4
  printf("worker6 %d - %s\n", x[1], str);
  return 0;
}

int main(){
	int result;
  // here we create an unnamed array somewhere on the stack
  // teststring is somewhere else on the stack
	result = worker5((int [2]){1,2}, "teststring");

  // the same call but worker6 uses a pointer internally
  result = worker6((int [2]){1,2}, "teststring2");
  return result;
}
