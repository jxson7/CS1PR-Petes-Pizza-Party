#include "money2.hpp"

Money2::Money2(long pounds,int pence)
{
	all_pence=pounds*100+pence;
}
// A display member function
void Money2::displayMoney(){
  long pounds;
  int pence;
  pounds=all_pence/100;
  pence=all_pence - (100*pounds);
  cout << "£"<<pounds<<"."<<pence<<endl;
}

// Overloaded operators
Money2 Money2 :: operator + (const Money2& amount2)
{
	Money2 temp;
	temp.all_pence = all_pence + amount2.all_pence ;
	return temp;
}

