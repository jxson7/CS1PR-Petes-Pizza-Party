#include <iostream>
#include <map>
using namespace std;

int main(){
  map<int, string> m;
  m[10] = "value at position 10";
  m[20] = "value at position 20";

  cout << m[5] << endl;
  cout << m[20] << endl;

  return 0;
}
