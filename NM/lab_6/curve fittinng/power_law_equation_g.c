#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4  // Number of data points

// Main function
int main() {
    double x[N] = {61, 26, 7, 2.6}; // x values
    double y[N] = {350, 400, 500, 600}; // y values

    double sum_X = 0.0, sum_Y = 0.0, sum_XY = 0.0, sum_XX = 0.0;
    double a, b;
    int i;

    // Loop to calculate sums of log-transformed values
    for (i = 0; i < N; i++) {
      // here X = log(x) and Y = log(y)
        sum_X += log(x[i]);
        sum_Y += log(y[i]);
        sum_XY += log(x[i]) * log(y[i]);
        sum_XX += log(x[i]) * log(x[i]);
    }

    // Calculate b and a
    b = (N * sum_XY - sum_X * sum_Y) / (N * sum_XX - sum_X * sum_X);
    a = exp((sum_Y - b * sum_X) / N);

    // Print the fitted equation
    printf("y = %.4f * x^%.4f\n", a, b);

    return 0;
}
/*
Output:
y = 701.9919 * x^-0.1709
*/