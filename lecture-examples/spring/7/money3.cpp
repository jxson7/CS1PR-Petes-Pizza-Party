#include "money3.hpp"


Money3::Money3(long pounds,int pence)
{
	all_pence=pounds*100+pence;
}

ostream &operator << (ostream &output, const Money3 & cash){
  long pounds;
  int pence;
  
  pounds=cash.all_pence/100;
  pence=cash.all_pence - (100*pounds);
  
  output << "£"<<pounds<<"."<<pence;
  return output;
}

void Money3::printMoney(bool license){
  string out;
  if(license){
    out = string("Money, Yay! ");
  }
  else{
    out = string("No Money, Boo! ");
  }
  cout << out << boolalpha << license << endl;
}

// Overloaded operators
Money3 Money3 :: operator + (const Money3& amount2)
{
	Money3 temp;
	temp.all_pence = all_pence + amount2.all_pence ;
	return temp;
}

