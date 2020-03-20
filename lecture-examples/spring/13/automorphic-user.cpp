#include <iostream>
#include <string>
#include <sstream>

#include <stdlib.h>

using namespace std;

bool isAutomorphic(int num);

int main(int argc, char ** argv){
  cout << argv[1] << " is " << (isAutomorphic(atoi(argv[1])) ? "automorphic" : " not automorphic :-(") << endl;
  return 0;
}
