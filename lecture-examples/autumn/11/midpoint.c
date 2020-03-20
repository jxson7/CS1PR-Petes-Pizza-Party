#include <stdio.h>
#include <math.h>

// compile with:
// gcc midpoint.c -lm
// we need to compile with the math library "libm"

double distanceToMidpoint(double x, double y) {
    double distance;
    x /= 2.0;
    y /= 2.0;
    distance = sqrt(x*x + y*y);
    return distance;
}

int main(void) {
    double x, y, result;
    x = 3;
    y = 4;
    result = distanceToMidpoint(x,y);
    printf("\nThe Distance To Midpoint is: %f\n", result);
    return 0;
}
