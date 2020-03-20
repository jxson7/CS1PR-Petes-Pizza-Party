#include "class_B.h" // class's header file
void B::set_k(){
	k = i + j;
}
int B::get_k(void){ 
	return k; 
}
void B::show(void){ 
	cout << "k = " << k << endl; 
}
