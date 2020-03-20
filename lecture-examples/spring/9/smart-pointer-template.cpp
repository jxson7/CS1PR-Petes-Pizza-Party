#include<iostream>
using namespace std;

// Templated version of a smart pointer, now with reference counting
template <typename T>
class SmartPointer {
   T *ptr;  // Actual pointer
   int *count; // Reference count
public:
   SmartPointer(T *p = NULL) {
     ptr = p;
     count = new int(1);
     cout << "C : reference count: " << *count << " counter address: " << count << endl;
   }

   ~SmartPointer() {
     // perform the reference counting
     (*count)--;
     cout << "D : reference count: " << *count << " counter address: " << count << endl;
     if(*count == 0){
       cout << "delete called" << endl;
       delete ptr;
       delete count;
     }
   }

   SmartPointer(SmartPointer<T> const & p){
     ptr = p.ptr;
     count = p.count;
     (*count)++; // increment reference counter
     cout << "CC: reference count: " << *count << " counter address: " << count << endl;
   }

   T & operator *() {
     return *ptr;
   }

   T * operator->() const {
     return ptr;
   }
};

void testFunc(SmartPointer<int> p){

}

class Object{
public:
  int val = 5;

  Object(){
    cout << "Object created" << endl;
  }

  ~Object(){
    cout << "Object destroyed" << endl;
  }
};

int main()
{
    SmartPointer<int> p(new int());
    *p = 10;
    cout << *p << endl; // This calls the overloaded operator

    auto p2 = p;
    testFunc(p2);

    // When p goes out of scope, the destructor for it is automatically
    // called and destructor does delete where ptr pointed to.

    SmartPointer<Object> po(new Object);
    cout << "PO val: " << po->val << endl;

    return 0;
}
