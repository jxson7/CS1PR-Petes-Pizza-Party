#include <iostream>
#include <string>
#include <vector>

#include <assert.h>

using namespace std;

bool canCapture(vector<string> const & vector){
  // check if both queens can "see" each other
  // positions of the queens?
  string q1 = vector[0];
  string q2 = vector[1];
  // horizontal
  if(q1[1] == q2[1]){
    return true;
  }
  // vertical
  if(q1[0] == q2[0]){
    return true;
  }
  // diagonal
  int first = q1[0] - q2[0]; // +2 | -2
  int second = q1[1] - q2[1]; // +2 | -2
  if(first == second || first == -second){
    return true;
  }

  return false;
}


int main(){
  assert(canCapture({"A1", "B2"}) == true);
  assert(canCapture({"A1", "C3"}) == true);
  assert(canCapture({"B3", "C2"}) == true);
  assert(canCapture({"A1", "H8"}) == true);
  assert(canCapture({"A1", "C2"}) == false);
  assert(canCapture({"G3", "E5"}) == true);
return 0;
}
