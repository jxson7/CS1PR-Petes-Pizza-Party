/* unit1.c */
// Compile with:
// gcc unit1.c unit2.c

#include "unit.h" /* correct */

int func(){
  return (1);
}

int main(){
  int x = 5;
  global_var = 10;
  printf("this is the main function\n");
  printf("x = %d\n", x);
  printf("global_var = %d\n", global_var);
  printf("\n");
  printValues();
  return(0);
}
