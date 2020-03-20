#include<iostream>
using namespace std;

// Templated version of a smart pointer for an array
template <typename T>
class SmartPointerArray {
   T *ptr;  // Actual pointer
   int *count; // Reference count
public:
   SmartPointerArray(T *p = NULL) {
     ptr = p;
     count = new int(1);
     cout << "C : reference count: " << *count << " counter address: " << count << endl;
   }

   ~SmartPointerArray() {
     // perform the reference counting
     (*count)--;
     cout << "D : reference count: " << *count << " counter address: " << count << endl;
     if(*count == 0){
       cout << "delete called" << endl;
       delete [] ptr;
       delete count;
     }
   }

   SmartPointerArray(SmartPointerArray<T> const & p){
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

   T & operator[] (int x) {
      return ptr[x];
   }
};

void testFunc(SmartPointerArray<int> p){

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
    SmartPointerArray<Object> po(new Object[5]);
    auto po2 = po;

    cout << "PO val: " << po[3].val << endl;
    cout << "PO val: " << po->val << endl;

    return 0;
}
