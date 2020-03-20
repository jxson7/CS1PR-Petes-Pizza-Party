#include <stdio.h>

// Compile with:
// gcc -O3 restrict.c
// O3 means use optimization level 3
// Without optimization you won't see the effect!

/**
* Here we use restrict to tell the compiler a, b, c don't overlap!
* It is the responsibility of the programmer to ensure this.
*/
void add_vector(int size, int * restrict a_out, int const * restrict b_in, int const * restrict c_in);

int main(){
  int a[] = {1,2,3,4};
  // the problem is that output and input can be the same pointer
  // like here:
  add_vector(4, a, a, a);

  for(int i=0; i < 4; i ++){
    // what does this print?
    printf("%d=%d\n", i, a[i]);
  }

  return 0;
}

void add_vector(int size, int * restrict a_out, int const * restrict b_in, int const * restrict c_in){
  for(int i=0; i < size; i ++){
    // the compiler assumes a, b and c point to different locations!
    a_out[i] += b_in[i];
    a_out[i] += c_in[i];
  }
}
