#include <iostream>
using namespace std;

int boxVol (int len, int wid = 2, int hei =3);

int main (){
	int first = 3;
  int second = 4;
  int third = 5;

	cout <<  boxVol(first)  << endl;
	cout <<  boxVol(first,second) << endl;
	cout <<  boxVol(first,second,third) << endl;
	return 0;
}

int boxVol (int len, int wid , int hei )
{
	return (len*wid*hei);
}
