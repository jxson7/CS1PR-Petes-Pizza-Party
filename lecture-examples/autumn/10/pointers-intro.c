#include <stdio.h>

// introductory example for pointers
// run several times to see countPtr change!

int main(int argc, char ** argv){
  int count = 5;

  int *countPtr = & count; // get the address from the variable count
  int count2 = *countPtr; // get the value from the integer countPtr points to
  printf("count=%d countPtr=%p count2=%d\n", count, countPtr, count2);
  return 0;
}
