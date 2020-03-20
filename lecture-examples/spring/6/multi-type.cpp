template<typename T, typename V>
class pair{
public:
  T first;
  V second;
};


int main(){
  pair<int, float> intFloat;

  intFloat.first = 5;
  intFloat.second = 6.256f;
  return 0;
}
