#include <stdio.h>


int keep_count(int new_value){
  static int count; // local variable which keeps value! Initialized with 0.
  count = count + new_value;
  return count;
}

int main(){
  printf("%d\n", keep_count(5)); // prints 5
  printf("%d\n", keep_count(5)); // prints 10
}
