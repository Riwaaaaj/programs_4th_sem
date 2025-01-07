#include <stdio.h>
#include <math.h>
/*
{ {3, 4, 5, 40},   // Equation 1: 3x + 4y + 5z = 40
  {1, 1, 1, 9},    // Equation 2: x + y + z = 9
  {2, -3, 4, 13} };// Equation 3: 2x - 3y + 4z = 13
*/

#define f1(x, y, z) ((40 - 4 * (y) - 5 * (z)) / 3)
#define f2(x, y, z) ((9 - (x) - (z)) / 1)
#define f3(x, y, z) ((13 - 2 * (x) + 3 * (y)) / 4)

int main() {

  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1;
  float e = 0.001, e1, e2, e3;
  int iteration = 1;

  do {
    x1 = f1(x0, y0, z0);
    y1 = f2(x1, y0, z0);
    z1 = f3(x1, y1, z0);

    e1 = fabs(x1 - x0);
    e2 = fabs(y1 - y0);
    e3 = fabs(z1 - z0);

    printf("%d\t%0.4f\t%0.4f\t%0.4f\n",iteration, x1,y1,z1);
    iteration++;
    x0 = x1;
    y0 = y1;
    z0 = z1;
  } while(e < e1 && e < e2 && e < e3);

  printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);//precision upto 3 decimal places
  return 0;
}