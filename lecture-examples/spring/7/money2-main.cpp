#include <iostream>
#include "money2.hpp"

using namespace std;

int main  (void)
{
  Money2 myPay(100,23);
  Money2 yourPay(77,50);
  Money2 income;

  income = myPay + yourPay; //use new op
  income.displayMoney();  
  return 0;
}
