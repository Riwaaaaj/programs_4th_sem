#include <stdio.h>
#include <math.h>

#define E 0.000001 

double f(double x) {
    return sin(x) - 1.0 / x;
}

double g(double x) {
    return cos(x) + 1.0 / x * x;
}

double newton_raphson(double x) {
    double x_next = x;
    double fx, fpx;
    int iter = 1;

    printf("iter\t x\t\t f(x)\n");
    while (1) {
        fx = f(x_next);
        fpx = g(x_next);

        printf("%d\t%lf\t%lf\n", iter, x_next, fx);

        if (fabs(fx) < E) {
            break;
        }

        if (fpx == 0) {
            printf("Error: Derivative is zero. Stopping iteration.\n");
            return x_next;
        }

        x_next = x_next - fx / fpx;
        iter++;
    }

    return x_next;
}

int main() {
    double initial_guess = 2;
    double root = newton_raphson(initial_guess);

    printf("The root is: %lf\n", root);
    return 0;
}