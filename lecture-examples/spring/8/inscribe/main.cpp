#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

// function prototype
void printShape(shape *p);

int main(int argc, char ** argv){

  shape A;
  float x1,y1, x2,y2;
  float r, cx, cy;
  if(argc == 1){
    cout << "Please enter the coords of the Rectangle you wish to create" << endl;
    cin >> x1 >> y1 >> x2>> y2 ;
    cout << "Please enter the radius and coordinates of centre of the circle you wish to create" << endl;
    cin >> r>>cx>>cy;
  }else{
    // create a rectangle that fits into the circle
    x1 = y1 = 0;
    cx = 6;
    cy = 8;

    r = 10;
    x2 = 6*2;
    y2 = 8*2;
  }

  // Call the constructors
  rectangle Box(x1,y1,x2,y2);
  circle Disk(r,cx,cy);

  // print the areas
  printShape(& A);
  printShape(& Box);
  printShape(& Disk);

  if(inscribed(Box,Disk)){
    cout << "The rectangle is inscribed by the circle" << endl;
  }
  else{
    cout << "The rectangle is NOT inscribed by the circle" << endl;
  }

  return 0;
}

void printShape(shape *p){
cout << "The area of your shape is: " << p->area()<<endl;
}
