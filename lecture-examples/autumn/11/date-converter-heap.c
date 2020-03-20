#include <stdio.h>
#include <stdlib.h> // needeed for malloc

// this is the date converter that uses malloc() and free to use the heap instead

struct date_t {
   char dayName[32];
   int day;
   int month;
   int year;
};

// This function returns a POINTER to the structure that is now stored on the heap.
struct date_t * dateConvert(char * input_date){
  struct date_t * d = malloc(sizeof(struct date_t));
  *d = (struct date_t){"Monday", 1, 11, 2019};
  return d;
}

int main(void) {
    struct date_t * d1;
    d1 = dateConvert("test");
    printf("struct size: %lu\n", sizeof(struct date_t));
    printf("%d.%d.%d it is %s\n", d1->day, d1->month, d1->year, d1->dayName);

    // the programmers responsibility to free the memory!
    free(d1);

    return 0;
}
