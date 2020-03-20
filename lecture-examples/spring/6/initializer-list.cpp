#include <initializer_list>

class myClass
{
public:
  myClass(std::initializer_list<float>){}
};


int main(){
  myClass newInstance{ 0.2f, 6.5f, 5.8f };

  return 0;
}
