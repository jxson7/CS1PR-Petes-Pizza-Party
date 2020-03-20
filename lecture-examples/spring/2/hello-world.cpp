#include <iostream>
// compile using g++ hello-world.cpp -o hello

int main(){
	int a, b, sum;
	std::cout << "Enter first integer\n";
	std::cin >> a;
	std::cout << "Enter second integer\n";
	std::cin >> b;

	sum = a + b;
	std::cout << "Sum is " << sum << std::endl;
	return 0;
}
