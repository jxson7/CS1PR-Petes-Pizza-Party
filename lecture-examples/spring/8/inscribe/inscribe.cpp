#include "rectangle.hpp"
#include "circle.hpp"

int inscribed(rectangle R, circle C){
  float Rcentrex, Rcentrey, diagRadius;
  // compute the centre of the rectangle
  Rcentrex = (R.upx+R.lowx)/2.0;
  Rcentrey= (R.upy+R.lowy)/2.0;
  // Compute the Radius of the circle which would inscribe the rectangle
  diagRadius = (Rcentrex - R.upx)*(Rcentrex - R.upx) + (Rcentrey - R.upy)*(Rcentrey - R.upy);
  // compare to the circle object
  if( ( Rcentrex == C.cx && Rcentrey == C.cy) && diagRadius == C.radius*C.radius ){
    return 1;
  }
  else{
    return 0;
  }
}
