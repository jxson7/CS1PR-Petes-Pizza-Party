#include <iostream>
#include <string>
#include <sstream>

#include <assert.h>

using namespace std;

static string to_str(long num){
  stringstream s1;
  s1 << num;
  return s1.str();
}

bool isAutomorphic(long num){
  long sqr = num * num;
  // compare if the last characters of sqr is identical to num
  // algorithm 1: convert both numbers to strings
  string result = to_str(sqr);
  // 5775
  //   01
  string nums = to_str(num);
  // 75
  // 01

  int rpos = result.size() - nums.size();
  for(int i=0; i < nums.size(); i++, rpos++){
    // reverse the position for the second string
    if(nums[i] != result[rpos]){
      return false;
    }
  }

  return true;
}
