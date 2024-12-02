#include <math.h>
#include <stdio.h>

static inline double f(double x) { return sin(x) - 1.0 / x; }

// double g(double x) { return x - f(x); }
static inline double g(double x) { return 1.0 / sin(x); }

int main() {
  double a = 1.0, xNext, e = 0.01;
  int iterations = 20;

  // printf("Enter initial guess: ");
  // scanf("%lf", &a);

  // printf("Enter error tolerance: ");
  // scanf("%lf", &e);

  // printf("Enter maximum iterations: ");
  // scanf("%d", &iterations);

  for (int i = 1; i <= iterations; i++) {
    xNext = g(a);

    printf("Iteration %d: x = %lf, f(x) = %lf\n", i, xNext, f(a));

    if (fabs(xNext - a) < e) {
      printf("Converged to solution x = %lf after %d iterations.\n", xNext, i);
      return 0;
    }
    a = xNext;
  }

  printf("Failed to converge within %d iterations.\n", iterations);
  return 0;
}