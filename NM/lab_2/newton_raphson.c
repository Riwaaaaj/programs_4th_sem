#include <math.h>
#include <stdio.h>
#include <stdlib.h>
static inline double f(double x) { return sin(x) - 1.0 / x; }
static inline double fPrime(double x) { return cos(x) + 1.0 / x * x; }

int main() {
  double x, e, xNext;
  int i = 1, maxIteration = 20;

  printf("Enter initial guess: ");
  scanf("%lf", &x);
  printf("Enter tolerable error: ");
  scanf("%lf", &e);

  printf("iter\t x\t\t f(x)\n");
  while (1) {
    if (fPrime(x) == 0) {
      printf("Error! Division by zero in %d iteration.\n", i);
      exit(1);
    }
    xNext = x - f(x) / fPrime(x);
    if (fabs(xNext - x) < e)
      break;
    printf("%d\t%lf\t%lf\n", i, xNext, f(xNext));
    x = xNext;
    if (i == maxIteration) {
      printf("Error! Failed to converge within %d iterations.\n", i);
      exit(1);
    }
    i++;
  }
  printf("Converged to solution x = %lf after %d iterations.\n", x, i - 1);
  return 0;
}
/*
Enter initial guess: 1.0
Enter tolerable error: 0.0001
iter     x               f(x)
1       1.102921        -0.014155
2       1.112676        -0.001849
3       1.113958        -0.000248
4       1.114130        -0.000033
Converged to solution x = 1.114130 after 4 iterations.
*/