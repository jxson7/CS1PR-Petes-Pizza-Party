template<typename T, typename V>
class pair{
public:
  pair(){}
  pair(T const & t, V const & v): first(t), second(v){}

  T first;
  V second;
};

pair<int, pair<int, pair<float,int>>> functionPPP(){
  return pair<int, pair<int, pair<float,int>>>();
}

int main(){
  auto var1 = functionPPP();
  auto var2 = functionPPP();

  return 0;
}
