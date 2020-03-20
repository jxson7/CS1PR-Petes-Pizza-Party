#include <stdbool.h>
#include <stdio.h>

#define COUNT 10

static void print_array(int n, int * arr);
static void swap(int * x, int * y);

void selectionSort(int n, int A[]){
  for (int i = 0; i < n; i++){
    int min = i;
    for (int j = i+1; j < n; j++){
      if (A[j] < A[min]){
        min = j;
      }
    }
    if(min != i){
      swap(& A[i], & A[min]); // that step makes the algorithm unstable
    }

    // to see it working:
    printf("One step: ");
    print_array(COUNT, A);
  }
}


int main(){
  int array[COUNT] = {24, 243, 1, -10, 14, 142, 0, -20, 14, -1};
  printf("Unsorted: ");
  print_array(COUNT, array);

  selectionSort(COUNT, array);

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
