#include <iostream>
#include "class_A.h"
#include "class_B.h"
#include "class_C.h"

using namespace std;
int main() {

  A a;
  int m, n;
  cin >> m >> n;
  a.set_ij(m,n);
  a.out_ij();

  B b;
  b.set_ij(m,n);
  b.set_k();
  b.show();

  C c;
  c.set_ij(m,n);
  c.out_ij();
  c.show();
  c.f(m,n);
  c.show();
}
