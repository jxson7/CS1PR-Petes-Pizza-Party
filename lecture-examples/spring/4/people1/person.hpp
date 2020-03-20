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
  void setName(string name) {
    this->name = name; // we use the "this" pointer to this object
  }

  string getName() {
    return name;
  }

  void setHairColor(hairColor_t hairColor){
    this->haircolor = hairColor;
  }

  hairColor_t getHairColor(){
    return haircolor;
  }

  void print(){
    cout << "Person \"" << name << "\", " << haircolor << endl;
  }
private:
  hairColor_t haircolor;
  string name;
};
