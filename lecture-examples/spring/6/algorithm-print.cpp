#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<string> output = { "HW", "EO", "LR", "LL", "OD" };
  copy(output.begin(), output.end(), ostream_iterator<string>(cout, "\n"));
  return 0;
}
