#include <stdio.h>
#include <stdlib.h> // needeed for malloc
#include <string.h> // needed for memset

int * create_int_array (int n){
  // how many bytes do we need to store n-many integers?
  void * arr = malloc( sizeof(int) * n );
  if (! arr){ // if memory cannot be allocated (memory full)
      printf("Critical error, cannot allocate array\n");
      exit(1);
  }

  // initialise the array to 0's, otherwise anything could be there
  memset(arr, 0, sizeof(int) * n);
  return arr;
}

void print_array(int n, int * arr){
  if(n <= 0) return;
  printf("%d", arr[0]);
  for(int i=1; i < n; i++){
    printf(",%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char ** argv){
  int n = 10000;
  if(argc == 2){
    // read input from command line, provide a default
    n = atoi(argv[1]);
  }
  int * arr = create_int_array(n);
  // do sth. interesting with the integer array
  print_array(n, arr); // we just print the array

  free(arr);
  // do not access the pointer in arr ever again, invalid!
  arr = NULL; // reduce programming error by setting it to NULL
  return 0;
}
