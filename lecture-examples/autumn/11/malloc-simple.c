#include <stdio.h>
#include <stdlib.h>

// very basic example that shows how to use the HEAP

int main(){
  // allocate 1024 Bytes of memory
  // it is your responsibility to manage this memory
  char * data = (char*) malloc(1024);

  // do whatever you want with the 1024 bytes that data points to
  printf("This example stores a string into the allocated memory\n");
  sprintf(data, "Hello World\n");
  // now print what we stored into memory
  printf("%s", data);

  // now free the memory again
  free(data);
  return 0;
}
