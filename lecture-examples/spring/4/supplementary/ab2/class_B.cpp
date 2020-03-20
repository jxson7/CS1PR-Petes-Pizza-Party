#include "class_B.h"

B::B(void){
m = 1;
cout << "Class B. Initial value of m = " << m << endl;
}
B::~B(void){
m = 0;
cout << "Class B. Final value of m = " << m << endl;
}
