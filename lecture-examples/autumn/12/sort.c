#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int age;
  char name[32];
} student_t;

int age_comparator(const void * a, const void * b){
  return ((student_t*)a)->age - ((student_t*)b)->age;
}

int name_comparator(const void * a, const void * b){
  return strcmp(((student_t*)a)->name,((student_t*)b)->name);
}

int main(){
  student_t students[] = {
      {.age = 30, .name = "Julian"},
      {.age = 28, .name = "Max"},
      {.age = 29, .name = "Anne-Marie"},
    };

  // use quicksort for sorting, we have 3 students
  qsort (students, 3, sizeof(student_t), age_comparator);
  printf("Lowest age: %s age: %d\n", students[0].name, students[0].age);

  qsort (students, 3, sizeof(student_t), name_comparator);
  printf("Alphanumerical sorting: %s age: %d\n", students[0].name, students[0].age);
  return 0;
}
