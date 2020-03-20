#include <iostream>
#include <cake.hpp>

using namespace std;

// compile with g++ -I. cake.cpp cake-main.cpp -o cake

int main()
{
	LongCake cake1; //instantiate cake1
	cout << "Cake is good" << endl;
	cout << "There are: " << cake1.GetSlices() << " left" << endl;

  cake1.EatSlice();
  cout << "Ate one, there are: " << cake1.GetSlices() << " left" << endl;

  while(cake1.EatSlice()){
    cout << "Ate one more, " << cake1.GetSlices() << " left" << endl;
  }
  cout << "No more cake" << endl;

  return 0;
}
