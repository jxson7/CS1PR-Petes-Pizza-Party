#include<iostream>
using namespace std;

// Illustrate the basic idea of a wrapper pointer on an integer data type
class SmartPointer {
   int *ptr;  // Actual pointer
public:
   SmartPointer(int *p = NULL) {
     ptr = p;
   }

   ~SmartPointer() {
     delete(ptr);
   }

   // Overloading dereferencing operator
   int & operator *() {
     return *ptr;
   }
};

int main()
{
    SmartPointer p(new int());
    *p = 10;
    cout << *p; // This calls the overloaded operator

    // When p goes out of scope, the destructor for it is automatically
    // called and destructor does delete where ptr pointed to.

    return 0;
}
