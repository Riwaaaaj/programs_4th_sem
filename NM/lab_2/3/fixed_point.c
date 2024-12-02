#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x) - 1.0 / x;
}

double g(double x) {
    return x - f(x); 
}

int main() {
    double x0, x, e;
    int iterations;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("Enter error tolerance: ");
    scanf("%lf", &e);

    printf("Enter maximum iterations: ");
    scanf("%d", &iterations);

    for (int i = 1; i <= iterations; i++) {
        x = g(x0); 

        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x, f(x));

        if (fabs(x - x0) < e) {
            printf("Converged to solution x = %lf after %d iterations.\n", x, i);
            return 0;
        }
        x0 = x;
    }

        
    printf("Failed to converge within %d iterations.\n", iterations);
    return 0;
}