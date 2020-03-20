#include <iostream>
#include "money.hpp"

using namespace std;

int main  (void)
{
  Money myPay(100,23);
  Money yourPay(77,50);
  Money income;

  income = myPay + yourPay; //use new op

  if (income == myPay){ // use new comparison
    cout<<"you earn nothing"<<endl;;
  }else{
    cout<<"you earn something"<<endl;
  }
  income.displayMoney();
  return 0;
}
