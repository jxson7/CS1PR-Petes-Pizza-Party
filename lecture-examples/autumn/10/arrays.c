#include <stdio.h>

// Arrays & pointers

int main(int argc, char ** argv){
  int row1[] = {2,5,21};
  int row2[] = {1,2,3};

  // dp is an array of two pointers to integers
  int * dp[2] = {& row1, & row2};
  // this will throw some warnings as the pointers are not compatible, but we are hackers!

  printf("dp[1][2]=%d\n", dp[1][2]);

  return 0;
}
