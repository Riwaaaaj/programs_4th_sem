#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4  // Number of data points

int main() {
    double x[N] = {61, 26, 7, 2.6}; // x values
    double y[N] = {350, 400, 500, 600}; // y values

    double sum_X = 0.0, sum_Y = 0.0, sum_XY = 0.0, sum_XX = 0.0;
    double a, b;
    int i;

    for (i = 0; i < N; ++i) {
      // here X = log10(x) and Y = log10(y) and A = log10(a)
        sum_X += log10(x[i]);
        sum_Y += log10(y[i]);
        sum_XY += log10(x[i]) * log10(y[i]);
        sum_XX += log10(x[i]) * log10(x[i]);
    }

    double delta = N * sum_XX - sum_X * sum_X;

    if (delta == 0) {
        printf("Cannot fit the line\n");
        exit(1);
    }

    b = (N * sum_XY - sum_X * sum_Y) / (N * sum_XX - sum_X * sum_X); // Cramer's rule
    a = pow(10, (sum_Y - b * sum_X) / N); // a = 10^((sum_Y - b * sum_X) / N)


    printf("y = %.4f * x^%.4f\n", a, b);

    return 0;
}/*Output: 
y = 701.9919 * x^-0.1709
*/