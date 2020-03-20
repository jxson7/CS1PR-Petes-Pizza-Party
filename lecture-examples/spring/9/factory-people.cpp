#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <algorithm>

using namespace std;

// just illustrates a variety of types
class Person{
public:
  virtual ~Person(){} // needed to support RTTI
};

class Student : virtual public Person{
  // virtual inheritance prevents diamond problem
};

class Employee : virtual public Person{
};

class PartTimeStudent : public Student, public Employee{
};

class Transformer : public Person{
};

class PeopleFactory{
public:
  Person * createPerson(vector<string> const & p){
    // check what properties are set
    bool p_car = find(begin(p), end(p), "car") != p.end();
    bool p_works = find(begin(p), end(p), "works") != p.end();
    bool p_studies = find(begin(p), end(p), "studies") != p.end();
    if(p_car){
      if(p_works || p_studies){
        throw exception();
      }
      return new Transformer();
    }
    if(p_studies){
      if(p_works){
        return new PartTimeStudent();
      }
      return new Student();
    }
    if(p_works){
      return new Employee();
    }
    // unknown property for now
    throw exception();
  }
};

int main(){
  PeopleFactory factory;
  Person * p = factory.createPerson({"works", "studies"});
  Person * p2 = factory.createPerson({"car"});

  cout << typeid(*p).name() << endl;
  cout << typeid(*p2).name() << endl;

  Person * p3 = factory.createPerson({"car", "works"});
}
