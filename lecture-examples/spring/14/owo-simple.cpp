#include <iostream>
#include <string>
#include <sstream>

#include <assert.h>

using namespace std;

string owofied(string const & test){
  string ret;
  //for(int i=0; i < test.size(); i++){
  for(auto & l : test){
    if(l == 'i' || l == 'e'){
      ret += 'w';
    }
    ret += l;
  }
  return ret + " owo";
}

int main(){
  assert(owofied("I'm gonna ride 'til I can't no more") == "I'm gonna rwidwe 'twil I can't no morwe owo");
  assert(owofied("Do you ever feel like a plastic bag") == "Do you wevwer fwewel lwikwe a plastwic bag owo");
  assert(owofied("Cause baby you're a firework") == "Causwe baby you'rwe a fwirwework owo");
  return 0;
}
