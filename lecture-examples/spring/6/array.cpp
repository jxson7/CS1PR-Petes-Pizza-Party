#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> ia;

  for(int i=0; i < 10; i++){
    ia.push_back(i);
  }

  cout << ia.size() << " " << ia[5] << endl;
  return 0;
}
