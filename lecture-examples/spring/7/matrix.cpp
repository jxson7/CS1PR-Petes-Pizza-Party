#include <iostream>

using namespace std;

// a 3x3 matrix
class Matrix{
public:
  Matrix(){
    // initialize
    for(int i=0; i < 3; i++){
      for(int j=0; j < 3; j++){
        a[i][j] = 0;
      }
    }
  }

  void print(){
    for(int i=0; i < 3; i++){
      for(int j=0; j < 3; j++){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
public:
  int a[3][3];
};

Matrix operator+ (Matrix const& m, int const& val){
  Matrix z = m;
  for(int i=0; i < 3; i++){
    for(int j=0; j < 3; j++){
      z.a[i][j] += val;
    }
  }
  return z;
}

int main(){
  Matrix a;
  a.print();
  cout << "Now we add the scalar 3 to it" << endl;
  a = a + 3;
  a.print();

  return 0;
}
