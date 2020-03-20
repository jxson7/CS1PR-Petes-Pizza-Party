#include <iostream>
#include <string>

using namespace std;


class Parent {
public:
    string hello() const {
      return "Parent";
    }

    virtual ~Parent(){ // add a destructur to make the parent Polymorphic

    }
};

class Child : public Parent {
public:
    string hello() const {
      return "Child";
    }
};

void basicCastExample(){
  double d = 3.14;
  // static cast allows to perform implicit type conversions
  void * p = & d;
  // static cast allows to change the type of a void pointer
  int * b = static_cast<int*>(p); // Returns a value of type int

  // const cast removes const
  int const * pc = b;
  int * pw = const_cast<int*>(pc);
}

void basicReinterpretCast(){
  size_t a;
  // reinterpreting a number as a pointer, static_cast cannot do that
  void * p = reinterpret_cast<void*>(4711);
  // reinterpreting the bit pattern as a pointer
  a = reinterpret_cast<size_t>(p);
}

void castObject(){
  // static cast with object references
  // assume we know that a reference is of a given type.
  Child c;
  cout << "Child c: " << c.hello() << endl;

  Parent & pc = c;
  cout << "Parent & pc = c : "
    << pc.hello() << endl;

  // we know that pc is of type Child
  Child & cr = static_cast<Child&>(pc);
  cout << "static_cast<Child&>(pc) : "
    << cr.hello() << endl;

  // static cast enforces the cast even if the object isn't of the right type:
  Parent p1;
  cr = static_cast<Child&>(p1);
  cout << "static_cast<Child&>(parent); this shouldn't happen and causes problems: "
    << cr.hello() << endl;
}

void dynamicCastObject(){
  // dynamic cast, this requires that the class is polymorphic, i.e., at least one virtual method
  Child c;
  cout << "Child c: " << c.hello() << endl;

  // dynamic cast will fail, as p1 is not a child
  Parent p1;
  Child & cr = dynamic_cast<Child&>(p1);
}



int main(){
  try{
    basicCastExample();
    basicReinterpretCast();
    castObject();
    dynamicCastObject();
  }catch(exception & b){
    cout << "Error :" <<  b.what() << endl;
  }

  return 0;
}
