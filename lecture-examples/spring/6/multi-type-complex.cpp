template<typename T, typename V>
class pair{
public:
  T first;
  V second;
};


int main(){
  pair<int, pair<int, float>> p;
  p.first = 5;
  p.second.first = 5;
  p.second.second = 6.25;

  return 0;
}
