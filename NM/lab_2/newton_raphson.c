#include <math.h>
#include <stdio.h>
#include <stdlib.h>
static inline double f(double x) { return sin(x) - 1.0 / x; }
static inline double fPrime(double x) { return cos(x) + 1.0 / x * x; }

int main() {
  double Xₚᵣₑᵥ, e, Xₙₑₓₜ;
  int i = 1, maxIteration = 20;
  // printf("Enter initial guess: ");
  // scanf("%lf", &Xₚᵣₑᵥ);
  Xₚᵣₑᵥ = 1.0;
  // printf("Enter tolerable error: ");
  // scanf("%lf", &e);
  e = 0.0001;

  printf("iter\t x\tf(x)\n");

  while (1) {

    if (fPrime(Xₚᵣₑᵥ) == 0) {
      printf("Error! Division by zero in %d iteration.\n", i);
      exit(1);
    }

    Xₙₑₓₜ = Xₚᵣₑᵥ - f(Xₚᵣₑᵥ) / fPrime(Xₚᵣₑᵥ);

    if (fabs(Xₙₑₓₜ - Xₚᵣₑᵥ) < e)
      break;

    printf("%d\t%.3lf\t%.3lf\n", i, Xₙₑₓₜ, f(Xₙₑₓₜ));

    Xₚᵣₑᵥ = Xₙₑₓₜ;

    if (i == maxIteration) {
      printf("Error! Failed to converge within %d iterations.\n", i);
      exit(1);
    }

    i++;
  }

  printf("Converged to solution x = %lf after %d iterations.\n", Xₚᵣₑᵥ, i - 1);
  
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