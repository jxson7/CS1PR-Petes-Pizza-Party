#include <iostream>
#include <string>

#include <assert.h>

using namespace std;

string firstNVowels(string const & str, int count){
  string vowels = "";
  int found = 0;
  // let's iterate through the word
  for(int i = 0 ; i < str.size(); i++){
    char l = str.at(i); // need to find out how to get the i-th letter in the string?
    // for each of the letters, check if it is a vowel
    if(l == 'a' || l == 'i' || l == 'o' || l == 'u' || l == 'e'){
      // if it is a vowel, then concatenate it with the previous found word
      vowels += l;
      found++;
      if(found >= count){
        break;
      }
    }
  }
  if(found < count){
    return "invalid";
  }
  return vowels;
}

int main(){
  assert(firstNVowels("sharpening skills", 3) == "aei");
  assert(firstNVowels("major league", 5) == "aoeau");
  assert(firstNVowels("hostess", 5) == "invalid");
  return 0;
}
