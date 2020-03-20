#include <stdio.h>
#include <stdlib.h>

enum type_e{
  TYPE_INTEGER
};

// Void pointer example
void inc_generic(void * p, enum type_e typ){
  switch(typ){
    case(TYPE_INTEGER):{
      int * i = (int*) p;
      (*i)++;
      break;
    }default:{
      printf("Unknown type\n");
      exit(0);
    }
  }
}

int main(int argc, char ** argv){
  int x = 5;
  inc_generic(&x, TYPE_INTEGER);
  //double y = 5.5;
  //inc_generic(&y, TYPE_DOUBLE);
  printf("x=%d\n", x);
  return 0;
}
