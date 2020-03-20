#include <stdio.h>


#define SIZE 3
int main(int argc, char ** argv){

  int i;
  int x[SIZE];
  int y = 44;
  for(i=0; i<SIZE; i++)
    x[i] = 1;
  for(i=0; i<=SIZE; i++) //wrong
    x[i] = 2;
  for(i=0; i<10; i++) //wrong
    x[i] = 3;

  printf("Did I crash now? How about y=%d\n", y);

  return 0;
}
