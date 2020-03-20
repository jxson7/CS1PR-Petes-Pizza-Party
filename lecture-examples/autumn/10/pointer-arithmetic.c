#include <stdio.h>

// Pointer arithmetic example

int main(int argc, char ** argv){
  int count = 5;

  int *p = & count; // get the address from the variable count

  // now we perform some arithmetic with this "address".
  printf("   p=%p \n p+1=%p \n p+2=%p\n",
    p,
    p + 1, // this is actually pointer arithmetic!
    p + 2);
  printf("Note that the address is incremented by sizeof(int) == %lu\n", sizeof(int));

  // alternative to pointer arithmetic:
  printf(" & p[0]=%p \n & p[1]=%p \n & p[2]=%p\n",
    & p[0], // get the address of the value of the first element in the array...
    & p[1],
    & p[2]);

  return 0;
}
