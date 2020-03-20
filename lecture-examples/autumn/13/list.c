#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

struct list_t{
  struct list_t *prev;
  void * elem;
  struct list_t *next; // the next element, NULL if none
};

typedef struct list_t list_t;

list_t * list_init(void * value){
  list_t * l = malloc(sizeof(list_t));
  memset(l, 0, sizeof(list_t)); // initialize with 0
  l->elem = value;
  return l;
}

void list_free(list_t * lst, void (*freefunc)(void* data)){
  while( lst && lst->prev != NULL ){
    lst = lst->prev;
  }
  while( lst != NULL ){
    if(freefunc) freefunc(lst->elem);
    list_t * cur = lst;
    lst = lst->next;
    free(cur);
  }
}

void list_unlink(list_t * lst){
  // remove lst element and ensure to recreate the pointers
  if(! lst) return;
  list_t * p = lst->prev;
  list_t * n = lst->next;
  if(p){
    p->next = n;
  }
  if(n){
    p->prev = p;
  }
}

list_t * list_push(list_t * list, void * elem){
  assert(list != NULL);
  list_t * l = malloc(sizeof(list_t));
  l->elem = elem;
  l->next = list->next;
  list->next = l;
  return l;
}

void * list_pop(list_t * list){
  assert(list != NULL);
  if(list->next == NULL) return NULL;
  list_t * next = list->next;
  list->next = next->next;
  void * elem = next->elem;
  free(next);
  return elem;
}

int main(){
  list_t * list = list_init();
  list_push(list, "this");
  list_push(list, "is");
  list_push(list, "a");
  list_push(list, "test");

  // we can iterate through the list:
  for(list_t * cur = list->next; cur != NULL; cur = cur->next){
    printf("%s ", (char const*) cur->elem);
  }
  printf("\n");

  void * first_elem = list_pop(list);
  printf("First: %s\n", (char const*) first_elem);

  return 0;
}
