#include <iostream>
#include <string>

using namespace std;

string abacabaPattern(int i){
  if(i == 0){
    return "";
  }
  string before = abacabaPattern(i-1);
  char letter = 'A' + i - 1;
  return before + letter + before;
}

int main(){
  for(int i=0; i < 10; i++){
    cout << abacabaPattern(i) << endl;
  }

  return 0;
}
