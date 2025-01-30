// y = a * log(x) + b
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

    for (i = 0; i < N; ++i) {
      // X = log10(x) and Y = y (no log on y)
        sum_X += log10(x[i]);
        sum_Y += y[i];
        sum_XY += log10(x[i]) * y[i];
        sum_XX += log10(x[i]) * log10(x[i]);
    }

    // Delta is calculated using Cramer's rule
    double delta = N * sum_XX - sum_X * sum_X;
    if (delta == 0) {
        printf("Cannot fit the line\n");
        exit(1);
    }

    b = (N * sum_XY - sum_X * sum_Y) / delta; // Slope
    a = (sum_Y - b * sum_X) / N; // Intercept

    printf("y = %.4f * log(x) + %.4f\n", a, b);

    return 0;
}/*Output: 
y = 665.3794 * log(x) + -181.9393
*/