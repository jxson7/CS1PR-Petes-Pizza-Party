#include <stdio.h>

// Compile with:
// gcc -O3 restrict-aliasing-problem.c
// O3 means use optimization level 3
// Without optimization you won't see the effect!

/**
* A prototype for vector addition,
* It is clarified how objects are used
* _out indicates it is generated; an output parameter
* _in: it is an input parameter
*/
void add_vector(int size, int * a_out, int const * b_in, int const * c_in);

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

void add_vector(int size, int * a_out, int const * b_in, int const * c_in){
  // when implementing func, this overlap of pointer can be tricky
  // also the compiler cannot perform optimizations
  for(int i=0; i < size; i ++){
    // the compiler must assume a, b and c can point to the same memory location
    a_out[i] += b_in[i];
    a_out[i] += c_in[i];
  }
}
