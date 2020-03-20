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
  // We use a constructor to initialize the person
  person(string const & name, hairColor_t color){
    this->name = name;
    this->haircolor = color;
  }

  person(){ // default constructor
    name = "Jane Doe";
    haircolor = COLOR_BROWN;
  }

  string getName() {
    return name;
  }

  hairColor_t getHairColor(){
    return haircolor;
  }

  void dyeHair(hairColor_t newColor){
    haircolor = newColor; // the compiler knows that haircolor is a member variable
  }

  void print(){
    cout << "Person \"" << name << "\", " << haircolor << endl;
  }
private:
  hairColor_t haircolor;
  string name;
};
