#ifndef MONEY_H
#define MONEY_H
#include <iostream>
using namespace std;
class Money
{
  // overloaded operators
  friend Money operator + (const Money& amount1, const Money& amount2);
  friend bool operator == (const Money& amount1, const Money& amount2);
 public:
  // constructor 
  Money(long = 0, int =0);
  //other functions to do things with money
  void displayMoney();

private:
  long all_pence;
};

#endif
