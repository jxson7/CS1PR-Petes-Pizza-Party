#include "money.hpp"

Money::Money(long pounds,int pence)
{
	all_pence=pounds*100+pence;
}
// A display member function
void Money::displayMoney(){
  long pounds;
  int pence;
  pounds=all_pence/100;
  pence=all_pence - (100*pounds);
  cout << "£"<<pounds<<"."<<pence<<endl;
}

// Overloaded operators
Money operator + (const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.all_pence = amount1.all_pence + amount2.all_pence ;
	return temp;
}

bool operator == (const Money& amount1, const Money& amount2)
{
	return(amount1.all_pence ==amount2.all_pence);
}
