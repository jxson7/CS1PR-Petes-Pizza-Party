#include <stdio.h>

// declaration
void func(int a, int b);

// definition
void func(int a, int b){
  int c;
  {
    int a = 3; // a shadows the function argument a
    int d = 4;
  }
  // d is not known outside the inner block
}

void func2(int a){
  int sqr(int a){
    return a*a;
  }
  printf("%d\n", sqr(a));
} // once leaving the block, the symbol sqr will be forgotten

int main(int argc, char ** argv){
  func(2, 5);
  sqr(5); // Will produce: warning: implicit declaration of function ‘sqr’
  return 0;
}
