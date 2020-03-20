#include "rectangle.hpp"

rectangle::rectangle(float ux, float uy, float lx, float ly){
  upx = ux;
  upy = uy;
  lowx = lx;
  lowy = ly;
  cout << "rectangle with sides " << fabs(upx-lowy) << "and "
       << fabs(upy-lowy) << " was created" << endl;
}

float rectangle::area(void){
  // Length of side is product of difference of x and y coordinates
  rect_area = (upy-lowy)*(upx-lowx);
  return rect_area;
}
