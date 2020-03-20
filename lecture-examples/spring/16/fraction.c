#include <stdio.h>
#include <stdlib.h>

/*
 Algorithm:
 Input: string Fraction Number (e.g., -14/6 = -12/6 - 2/6)
 Output: string Mixed Number (e.g. -2 1/3)

 parse input into sign numerator and denominator

 whole = input numerator int divide by input denominator (e.g. 14/6 = 2)
 remainder = input numerator remainder of int division by input denominator  (14%6 = 2)
 output whole remainder/denominator (e.g., 2 2/6)
 */

void mixedNumber(char * output, int output_len, char const* input){
  int numerator;
  int denominator;
  //snprintf(output, output_len, "10/4");
  *output = '\0';

  if(input[0] == '-'){
    // input -> -200
    output += snprintf(output, output_len, "-");
    input++;
    // input -> 200
  }
  numerator = atoi(input); // how many characters did we parse?
  // find the division character "/"
  // go through string to find "/"

  while(input[0] != '/' && *input != '\0') input++;
  if(*input == '/'){
    denominator = atoi(input + 1);
  }
  printf("%d denominator %d\n", numerator, denominator);
  return;
}

int main(int argc, char const ** argv){
  char output[2000];
  mixedNumber(output, 2000, "-200/60");
  printf("%s\n", output);
  return 0;
}
