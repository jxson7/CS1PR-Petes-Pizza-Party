#include <string>

using namespace std;

class Car{
public: // visibility, will be taught later
     // DATA
     int registration;
     string colour;
     // METHODS, i.e., functions on objects
     int getRegistration() { return registration; }
     string getColour() { return colour; }

     void setRegistration(int pReg){
       registration = pReg;
     }
     void setColour(string pColour){
       colour = pColour;
     }
};
