#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

typedef void * stack_elem_t;

typedef struct {
  uint32_t capacity; // max number of elements
	uint32_t size;
	stack_elem_t collection[]; // array of elements, this trick works at the end of a struct
} stack_t;

stack_t *stack_init(uint32_t capacity){
  stack_t * s = malloc(sizeof(stack_t) + sizeof(void*) * capacity);
  s->capacity = capacity;
  s->size = 0;
  return s;
}

void stack_push(stack_t *s, void * elem){
  assert(s->size < s->capacity);
  s->collection[s->size] = elem;
  s->size++;
}

void * stack_pop(stack_t *s){
  if(s->size == 0){ // empty
    return NULL;
  }
  s->size--;
  return s->collection[s->size];
}

void stack_destroy(stack_t * s, void (*freefunc)(void* elem)){
  // we must cleanup elements properly, if we manage the stack
  if(freefunc){
    for(uint32_t i=0; i < s->size; i++){
      freefunc(s->collection[i]);
    }
  }
  free(s);
}

int main(){
  // Example storing text references inside the stack.
  // Strings lives on the TEXT segment, so we can use the pointer directly
  stack_t * s = stack_init(100);
  stack_push(s, "this");
  stack_push(s, "is");
  stack_push(s, "a");
  stack_push(s, "test");

  while(true){
    stack_elem_t * elem = stack_pop(s);
    if(! elem) break;
    printf("%s ", (char const *) elem);
  }
  printf("\n");
  stack_destroy(s, NULL);

  // example giving the ownership of the elements to the stack
  s = stack_init(10);
  int32_t *p;
  p = malloc(sizeof(int32_t));
  *p = 4;
  stack_push(s, p);
  p = malloc(sizeof(int32_t));
  *p = 4711;
  stack_push(s, p);
  stack_elem_t * elem = stack_pop(s);
  // now we own the memory of elem again!
  printf("%d\n", *(uint32_t*) elem);
  free(elem);
  stack_destroy(s, free);

  return 0;
}
