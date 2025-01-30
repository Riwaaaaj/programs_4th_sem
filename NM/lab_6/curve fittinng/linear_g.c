#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void linearFit(double x[], double y[], int n, double *a, double *b) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    int i;

    for (i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    double delta = n * sum_xx - sum_x * sum_x;
    if (delta == 0) {
        printf("Cannot fit the line\n");
        exit(1);
    }

    *a = (n * sum_xy - sum_x * sum_y) / delta; // by cramers rule.
    *b = (sum_y - (*a) * sum_x) / n; // from normal equation 1
}
int main() {
    double x[] = {1, 2, 3, 4, 6, 8};  // X values
    double y[] = {2.4, 3, 3.6, 4, 5, 6};  // Y values

    int n;  // Number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n > sizeof(x) / sizeof(x[0])) {
        printf("Error: Number of points exceeds data size.\n");
        return 1;
    }

    double a, b;  // Coefficients
    linearFit(x, y, n, &a, &b);

    printf("a = %f, b = %f\n", a, b);
    printf("The best fit line is y = %.4f + %.4f * x\n", b, a);

    return 0;
}/*Output:
Enter the number of data points: 6
a = 0.505882, b = 1.976471
The best fit line is y = 1.9765 + 0.5059 * x   */