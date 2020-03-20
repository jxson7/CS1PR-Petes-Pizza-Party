#include <iostream>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;

string owofied(string const & test){
  string ret = test;
  size_t pos;
  // this doesn't work! fix it!
  while((pos = ret.find("i")) != string::npos){
    ret.replace(pos, 1, "wi");
    cout << ret << endl;
  }
  return ret + " owo";
}

int main(){
  assert(owofied("I'm gonna ride 'til I can't no more") == "I'm gonna rwidwe 'twil I can't no morwe owo");
  assert(owofied("Do you ever feel like a plastic bag") == "Do you wevwer fwewel lwikwe a plastwic bag owo");
  assert(owofied("Cause baby you're a firework") == "Causwe baby you'rwe a fwirwework owo");
  return 0;
}
