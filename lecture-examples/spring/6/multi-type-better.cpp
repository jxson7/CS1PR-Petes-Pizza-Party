template<typename T, typename V>
class pair{
public:
  pair(){}
  pair(T const & t, V const & v): first(t), second(v){}

  T first;
  V second;
};


int main(){
  pair<int, pair<int, float>> intFloat(5, {5,6.25});

  return 0;
}
