#include <stdio.h>

// this example deals with bit-operators
// compile on the terminal with:
// gcc bit-operators.c
// run with:
// ./a.out

int main(int argc, char ** argv){
  int number = 6;
  // which is 2+4, hence those two bits are set
  printf("number: %d, of this value the\n", number);

  // the bit_value can be extracted using the bit-wise operator "&"
  printf("- rightmost bit has value:  %d\n", number & 1 );
  printf("- second bit has the value: %d\n", number & 2 );
  printf("- third bit has the value:  %d\n", number & 4 );
  printf("- forth bit has the value:  %d\n", number & 8 );

  // how can we check if the (i+1)-th bit is set and print this?
  int i = 2; // hence we check for the 3-rd bit

  // shift the number to the right by i positions
  // use & with the bit-pattern ...0000001 = 1 to only extract a single bit
  int bit = 1 & (number>>i);
  printf("The %d-bit of the number is %d\n", i, bit);

  return 0;
}
