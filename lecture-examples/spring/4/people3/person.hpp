#include <string>
#include <iostream>

using namespace std;

typedef enum{ // enums from C
  COLOR_BLACK,
  COLOR_BLUE,
  COLOR_RED,
  COLOR_GREEN,
  COLOR_BROWN
} hairColor_t;

class person{
public:
  person(string full_name, int nhs_number, hairColor_t haircolor) :  // member initializer list
    name(full_name), nhs(nhs_number), haircolor(haircolor)
    {
      // empty constructor
    }

  string getName() {
    return name;
  }

  hairColor_t getHairColor(){
    return haircolor;
  }

  void dyeHair(hairColor_t newColor){
    haircolor = newColor;
  }

  void print(){
    cout << "Person \"" << name << "\", " << nhs << ", " << haircolor << endl;
  }
protected:
  hairColor_t haircolor;
  string name;
  int nhs;
};

class student : public person{
public:
  student(string full_name, int nhs_number, hairColor_t haircolor, int student_id) :
    student_id(student_id),
    person(full_name, nhs_number, haircolor) // call constructor of parent class person
    {

    }

  int getStudentID(){
    return student_id;
  }

  void print(){
    cout << "Student \"" << name << "\", " << nhs << ", " << haircolor << ", " << student_id << endl;
  }
protected:
  int student_id;
};
