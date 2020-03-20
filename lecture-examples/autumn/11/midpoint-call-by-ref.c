#include <stdio.h>
#include <math.h>

// compile with:
// gcc midpoint.c -lm
// we need to compile with the math library "libm"

// here we are able to change x and y as these are pointers
void calculateMidpoint(double * x, double * y) {
    *x /= 2.0;
    *y /= 2.0;
}

int main(void) {
    double x, y, result;
    x = 10.0;
    y = 12.5;
    calculateMidpoint(& x, &y); // this modifies the values of x and y!
    printf("The Midpoint is: (%.1f,%.1f) \n", x, y);
    return 0;
}
