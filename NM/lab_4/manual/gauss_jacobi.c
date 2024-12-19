#include<stdio.h>
#include<math.h>
/* Arrange systems of linear quations to be solved in diagonally dominant form and form equation for each unknown and define here
*/
/* Arranging given system of linear equations in diagonally dominant form: 20x + y - 2z = 17
3x + 20y -z = -18
2x - 3y + 20z = 25
*/
/* Defining function */
// #define f1(x,y,z) (17 - y + 2 * z) / 20 
// #define f2(x,y,z) (-18 -3 * x + z) / 20 
// #define f3(x,y,z) (25 -2 * x + 3 * y) /20


#define f1(x,y,z) (25 + 3 * y - 20 * z) / 2 
#define f2(x,y,z) 17 + 2 * z - 20 * x
#define f3(x,y,z) 3 * x + 20 * y + 18

int main() {
float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e; //declaring variable with initial guess...
int count=1;
printf("Enter tolerable error:\n"); scanf("%f", &e);
printf("\nCount\tx\ty\tz\n"); 
do {
  /* Calculation */
x1 = f1(x0,y0,z0);
y1 = f2(x0,y0,z0);
z1 = f3(x0,y0,z0); 
printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);
/* Error */
e1 = fabs(x0-x1); //fabs is absolute value.. 
e2 = fabs(y0-y1);
e3 = fabs(z0-z1);
count++;
/* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
}while(e1>e && e2>e && e3>e);
printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);//precision upto 3 decimal places
return 0;
}

// Take different initial values
// make iterative equation from non-diagonal position.

/*

Enter tolerable error:
0.002

Count   x       y       z
1       1.0500  -0.8000 1.2500
2       1.0150  -0.9950 1.0250
3       1.0022  -1.0010 0.9992
4       1.0000  -1.0004 0.9996

Solution: x=1.000, y=-1.000 and z = 1.000

*/