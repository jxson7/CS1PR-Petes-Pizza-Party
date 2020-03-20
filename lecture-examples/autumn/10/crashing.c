#include <stdio.h>


int main(int argc, char ** argv){
  int *p = 4004;
  // you can supress the compiler warning by an explicit type cast!
  int *p2 = (int*) 4004;
  printf("This program most likely crashes now with a Segmentation Fault!\n");
  *p = 2;

  return 0;
}
