#include <stdio.h>

int main(int argc, char ** argv){

  int *a[3]; // array of 3 pointers
  a[0] = (int[3]){1,2,3};
  a[1] = (int[3]){4,5,6};
  a[2] = (int[3]){7,8,9};

  printf("a[0][1]=%d\n", a[0][1]);

  // now practice by printing the memory locations of each subarray!

  return 0;
}
