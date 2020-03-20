#include <stdio.h>

int func(register int r){ // place inside register
  return r;
}

int main(){
  register int heavy = 5; // place inside register
  // do a lot with heavy
  printf("%d\n", func(heavy));
}
