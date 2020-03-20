#ifndef MONEY3_H
#define MONEY3_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Money3
{
  friend ostream &operator <<(ostream &, const Money3 & cash); 
 public:
  // constructor 
  Money3(long = 0, int =0);
  //other functions to do things with money
  // makeMoney()
  void printMoney(bool license);// Legal in C++ if not the real world
  // overloaded operators as member function
  Money3 operator + (const Money3& amount2);
  
 private:
  long all_pence;
};

#endif
