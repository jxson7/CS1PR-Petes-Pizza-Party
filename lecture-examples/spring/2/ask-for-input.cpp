#include <iostream>
using namespace std;
int main() {
	int a, b, sum;
	cout << "Enter first integer a \n";
	cin >> a;
	cout << "Enter second integer b \n";
	cin >> b;
	if(a>b){
		cout << "a is bigger than b\n";
	}else{
		cout << "b is bigger than a or equal to a\n";
	}

	return 0;
}
