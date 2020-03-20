#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 https://edabit.com/challenge/9X9T7zPshHbqzdGHy

 Algorithm:
 Input: string Fraction Number (e.g., -14/6 = -12/6 - 2/6)
 Output: string Mixed Number (e.g. -2 1/3)

 parse input into sign numerator and denominator

 whole = input numerator int divide by input denominator (e.g. 14/6 = 2)
 remainder = input numerator remainder of int division by input denominator  (14%6 = 2)
 output whole remainder/denominator (e.g., 2 2/6)
 */

string mixedNumber(string input){
  char sign;
  int numerator;
  int denominator;
  stringstream output;

  stringstream in(input);
  // -14/6
  in >> sign;
  if(sign != '-'){
    in = stringstream(input);
  }else{
    output << "-";
  }
  in >> numerator;
  char divchar;
  in >> divchar;
  // need to finish this example :-)
  in >> denominator;

  // whole = input numerator int divide by input denominator (e.g. 14/6 = 2)
  int whole = numerator / denominator;
  if(whole != 0){
    output << whole << " ";
  }
  // remainder = input numerator remainder of int division by input denominator  (14%6 = 2)
  int remainder = numerator % denominator;
  // output whole remainder/denominator (e.g., 2 2/6)

  // simplify the remainder and denominator (e.g. 2/6)
  for(int i=(denominator/2); i > 1; i--){
    if(remainder % i == 0 && denominator % i == 0){
      remainder /= i;
      denominator /= i;
    }
  }
  output << remainder;
  if(denominator != 1 || denominator != 0){
    output  << "/" << denominator;
  }
  return output.str();
}

int main(int argc, char const ** argv){
  cout << mixedNumber("-200/60") << endl;
  cout << mixedNumber("-2") << endl;
  return 0;
}
