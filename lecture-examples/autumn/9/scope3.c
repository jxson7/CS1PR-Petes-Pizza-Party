#include <stdio.h>

static int var = 4; // only visible inside this compilation unit == this file and all includes!
// to test, run after compilation $ nm ./a.out

int main(){
  printf("%d\n", var);
}
