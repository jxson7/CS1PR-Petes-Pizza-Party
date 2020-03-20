#include <iostream>
using namespace std;

template <typename T>
class property{
public:
    void Set (T value)
    { storage = value; }

    T Get ()
    { return storage; }

protected:
    T storage;
};

int main(){
  property<int> intInst;
  property<float> floatInst;
  property<string> stringInst;

  intInst.Set(5);
  floatInst.Set(6.5);
  stringInst.Set("Hello!");
  return 0;
}
