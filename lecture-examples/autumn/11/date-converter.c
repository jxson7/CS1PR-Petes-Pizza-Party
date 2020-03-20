#include <stdio.h>

struct date_t {
   char dayName[32];
   int day;
   int month;
   int year;
};

// This function returns the whole structure via the struct
struct date_t dateConvert(char * input_date){
  // ignore the input data for now...
  struct date_t d = {"Monday", 1, 11, 2019};
  return d;
}

int main(void) {
    struct date_t d1;
    d1 = dateConvert("test");
    printf("struct size: %lu\n", sizeof(struct date_t));
    printf("%d.%d.%d it is %s\n", d1.day, d1.month, d1.year, d1.dayName);
    return 0;
}
