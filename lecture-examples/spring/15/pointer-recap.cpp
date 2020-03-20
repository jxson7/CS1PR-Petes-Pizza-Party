#include <stdio.h>

struct player{
  int health;
  char const * name;
};

void print_modify_player(struct player * p1){
  printf("%d %s\n", (*p1).health, (*p1).name);
  // (*p).x => p->x
  p1->health--;
}

int main(){
  int var = 4711;

  int * p = & var;
  printf("%d\n", *p);

  struct player p1;
  p1.health = 1;
  p1.name = "C++ Lecture";

  print_modify_player(& p1);
  print_modify_player(& p1);

  return 0;
}
