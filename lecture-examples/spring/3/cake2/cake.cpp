#include <iostream>
#include <cake.hpp>

using namespace std;

// compile with g++ -I. cake.cpp cake-main.cpp -o cake

// Constructor - Called every time a new instance of a class is made
Cake::Cake( )
{
	bPlate = true; // plate for putting the cake on
	iSlices = 8; //cake is cut initially with 8 slices
}

//Destructor - called when the object is deleted,
// to tidy up any memory allocation
// to prevent memory leakage
Cake::~Cake( )
{
	iSlices = 0; // throw away any uneaten cake
	bPlate = false; //put plate away
}


bool Cake::EatSlice()
{
	if (iSlices > 0 )
	{
		iSlices--;
		return true;
	}
	else
		return false;
}


int Cake::GetSlices()
{
	return iSlices;
}

LongCake::LongCake() : Cake(){
  iSlices = 12;
}
