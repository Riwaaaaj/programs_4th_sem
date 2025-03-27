#include <math.h>
#include <stdio.h>
#include <stdlib.h>
static inline double f(double x) { return sin(x) - 1.0 / x; }
static inline double g(double x) { return 1.0 / sin(x); }
int main() {
  double Xₚᵣₑᵥ, e, Xₙₑₓₜ;
  int i, maxIteration = 20;
  printf("Enter initial guess: ");
  scanf("%lf", &Xₚᵣₑᵥ);
  printf("Enter tolerable error: ");
  scanf("%lf", &e);

  for (i = 1; i <= maxIteration; ++i) {
    Xₙₑₓₜ = g(Xₚᵣₑᵥ);
    printf("Iteration %d: x = %lf, f(x) = %lf\n", i, Xₙₑₓₜ, f(Xₚᵣₑᵥ));
    if (fabs(Xₙₑₓₜ - Xₚᵣₑᵥ) < e)
      break;
    Xₚᵣₑᵥ = Xₙₑₓₜ;
    if (i == maxIteration) {
      printf("Error! Failed to converge within %d iterations.\n", i);
      exit(1);
    }
  }
  printf("Converged to solution x = %lf after %d iterations.\n", Xₙₑₓₜ, i);
  return 0;
}
/*
Output:
        Enter initial guess: 1.0
        Enter tolerable error: 0.0001
        Iteration 1: x = 1.188395, f(x) = -0.158529
        Iteration 2: x = 1.077852, f(x) = 0.086300
        Iteration 3: x = 1.135147, f(x) = -0.046828
        Iteration 4: x = 1.103027, f(x) = 0.025653
        Iteration 5: x = 1.120352, f(x) = -0.014020
        Iteration 6: x = 1.110798, f(x) = 0.007678
        Iteration 7: x = 1.116005, f(x) = -0.004201
        Iteration 8: x = 1.113148, f(x) = 0.002300
        Iteration 9: x = 1.114710, f(x) = -0.001259
        Iteration 10: x = 1.113855, f(x) = 0.000689
        Iteration 11: x = 1.114323, f(x) = -0.000377
        Iteration 12: x = 1.114067, f(x) = 0.000206
        Iteration 13: x = 1.114207, f(x) = -0.000113
        Iteration 14: x = 1.114130, f(x) = 0.000062
        Converged to solution x = 1.114130 after 14 iterations.
 */
