#ifndef MONEY2_H
#define MONEY2_H
#include <iostream>
using namespace std;
class Money2
{
 public:
  // constructor 
  Money2(long = 0, int =0);
  //other functions to do things with money
  void displayMoney();
  // overloaded operators
  Money2 operator + (const Money2& amount2);
  
 private:
  long all_pence;
};

#endif
