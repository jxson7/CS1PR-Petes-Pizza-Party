#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<string> list = { "Computers", "Scientists", "Routers", "Monitors" };

  for (vector<string>::iterator i = list.begin(); i != list.end(); i++){
  // could have used: "auto i = " instead
      cout << i->length() << ": " << *i <<  endl;
  }
  return 0;
}
