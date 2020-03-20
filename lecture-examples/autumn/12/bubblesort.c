#include <stdbool.h>
#include <stdio.h>

#define COUNT 10

static void print_array(int n, int * arr);
static void swap(int * x, int * y);

void bubbleSort(int n, int A[]){ // n is the length of array
  bool swapped;
  do{
    swapped = false;
    for (int i = 1; i < n; i++){
      if (A[i-1] > A[i]){
        swap( & A[i-1], & A[i]); // this swaps the two neighbouring array elements
        swapped = true;
      }
    }
    n = n - 1;

    // to see it working:
    printf("One step: ");
    print_array(COUNT, A);

  } while (swapped);
}

int main(){
  int array[COUNT] = {24, 243, 1, -10, 14, 142, 0, -20, 14, -1};
  printf("Unsorted: ");
  print_array(COUNT, array);

  bubbleSort(COUNT, array);

  printf("Sorted:   ");
  print_array(COUNT, array);

  return 0;
}

static void swap(int * x, int * y){
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

static void print_array(int n, int * arr){
  if(n <= 0) return;
  printf("%d", arr[0]);
  for(int i=1; i < n; i++){
    printf(",%d", arr[i]);
  }
  printf("\n");
}
