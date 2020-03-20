#include <iostream>
#include "money3.hpp"

using namespace std;

int main  (void)
{
  Money3 myPay(100,23);
  Money3 yourPay(77,50);
  Money3 income;

  income = myPay + yourPay; //use new op
  cout << "My Pay " << myPay << endl;
  cout << "Your Pay " << yourPay << endl;
  cout << "Our Pay " << income << endl;
  income.printMoney((bool)1);
  return 0;
}
