#include <stdio.h>

typedef struct {
  int id;
  char name[20];
} user_t;

int main(int argc, char ** argv){
  user_t x;
  x.id = 5; // remember, the dot-punctuator (.) is how to access a member of a struct!

  user_t *p; // this is a pointer to a struct object, it is not yet set to anything
  p = &x;


  (*p).id = 4; // setting the id the pointer points to, cumbersome
  p->id = 4; // this is an equivalent notation

  printf("p->id=%d is the same as (*p).id=%d\n", p->id, (*p).id);
  return 0;
}
