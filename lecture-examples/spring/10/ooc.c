#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declaration
struct person;
struct student;

typedef struct{
  void (*destroy)(struct person*); // generic object destroy function
  void (*printDetails)(struct person*);
} person_ftbl_t;

typedef struct{
  person_ftbl_t super;
  int (*getMatrikel)(struct student*);
} student_ftbl_t;

typedef struct person{
  person_ftbl_t * tbl;
  int age;
  char name[32];
} person_t;

typedef struct student{
  person_t super;
  student_ftbl_t * tbl;

  int matrikel;
} student_t;

// IMPLEMENTATION of person
void person_print_details(person_t * p){
  printf("Person<%s,%d>\n", p->name, p->age);
}

void person_destroy(person_t * p){
  // free allocated memory
  free(p);
}

// a global virtual address table for person!
person_ftbl_t person_v_addr = {
  .destroy = person_destroy,
  .printDetails = person_print_details
};

person_t * person_ctor(int age, char * name){
  person_t * p = malloc(sizeof(person_t));
  p->age = age;
  strcpy(p->name, name);
  p->tbl = & person_v_addr;
  return p;
}

// IMPLEMENTATION of student
void student_print_details(person_t * p){
  student_t * s = (student_t*) p;
  printf("Student<%s,%d,matrikel: %d>\n", p->name, p->age, s->matrikel);
}

int student_getMatrikel(struct student* s){
  return s->matrikel;
}

// use a global virtual address table for person!
student_ftbl_t student_v_addr = {
  .super = {.destroy = person_destroy,
            .printDetails = student_print_details},
  .getMatrikel = student_getMatrikel
};

student_t * student_ctor(int age, char * name, int matrikel){
  student_t * p = malloc(sizeof(student_t));
  p->matrikel = matrikel;
  p->super.age = age;
  strcpy(p->super.name, name);
  p->tbl = & student_v_addr;
  // we also replace the parent table!
  p->super.tbl = (person_ftbl_t*) & student_v_addr;
  return p;
}


int main(){
  person_t * p = person_ctor(35, "Fritz");
  p->tbl->printDetails(p);

  student_t * s = student_ctor(25, "Miriam Studies", 3712);
  s->tbl->super.printDetails(s); // note how we access super here!

  // a student actually is a person, so we can call these functions!
  person_t * m = (person_t*) s;
  m->tbl->printDetails(m);

  // free memory again
  p->tbl->destroy(p);
  s->tbl->super.destroy(s);

  return 0;
}
