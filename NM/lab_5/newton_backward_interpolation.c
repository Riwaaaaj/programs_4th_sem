#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

float newtonBackwardInterpolation(int n, float x[], float y[], float x0) {
    float y0 = y[n - 1]; // Initial value from the last entry
    float h = x[1] - x[0]; // Assuming uniform spacing
    float u = (x0 - x[n - 1]) / h;
    float backward[n][n];

    for (int j = 0; j < n - 1; j++) {
        for (int i = n - 1; i > j; i--) {
            if (j == 0) {
                backward[i][j] = y[i] - y[i - 1];
            } else {
                backward[i][j] = backward[i][j - 1] - backward[i - 1][j - 1];
            }
        }
    }

    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f\t", y[i]);
        for (int j = 0; j < n - i - 1; j++) {
            printf("%.4f\t", backward[n - 1 - i][j]);
        }
        printf("\n");
    }
    float product = 1;
    for (int j = 1; j < n; j++) {
        product *= (u + (j - 1));
        y0 += (product * backward[n - 1][j - 1]) / factorial(j);
    }

    return y0;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n]; // Arrays to store data points

    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    float x0;
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &x0);

    float result = newtonBackwardInterpolation(n, x, y, x0);
    printf("The interpolated value at x = %.4f is: %.4f\n", x0, result);

    return 0;
}/*
Program execution:
Enter the number of data points: 6
Enter the data points (x and y):
x[0] y[0]: 2 5.1
x[1] y[1]: 4 4.2
x[2] y[2]: 6 3.1
x[3] y[3]: 8 3.5
x[4] y[4]: 10 6.2
x[5] y[5]: 12 7.3
Enter the value of x for interpolation: 11

Backward Difference Table:
5.1000  1.1000  -1.6000 -3.9000 -4.7000 -3.8000
4.2000  2.7000  2.3000  0.8000  -0.9000
3.1000  0.4000  1.5000  1.7000
3.5000  -1.1000 -0.2000
6.2000  -0.9000
7.3000
The interpolated value at x = 11.0000 is: 7.4812

*/