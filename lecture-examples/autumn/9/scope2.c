#include <stdio.h>

int global_var = 4; // external variable, can be accessed everywhere in all linked code.
// to test, run after compilation $ nm ./a.out

int main(){
  printf("%d\n", global_var);
}
