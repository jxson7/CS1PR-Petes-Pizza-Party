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

  // overload [] operator
  int & operator() (int x, int y){
    return a[x][y];
  }

// allow access to the private member
friend Matrix operator+ (Matrix const& m, int const& val);

private:
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
  a = a + 3;
  a.print();

  cout << "Printing element a[1][2]" << endl;
  cout << a(1,2) << endl;

  cout << "Setting element a[1][2] to 4" << endl;
  a(1,2) = 4;
  cout << a(1,2) << endl;

  return 0;
}
