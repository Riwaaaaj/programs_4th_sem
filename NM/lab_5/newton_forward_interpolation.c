#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to perform Newton's Forward Interpolation
float newtonForwardInterpolation(int n, float x[], float y[], float x0) {
    float y0 = y[0]; // Initial value of interpolation
    float u = (x0 - x[0]) / (x[1] - x[0]);
    float forward[n][n];

    // Calculating the forward difference table
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - j - 1; i++) {
            if (j == 0) {
                forward[i][j] = y[i + 1] - y[i];
            } else {
                forward[i][j] = forward[i + 1][j - 1] - forward[i][j - 1];
            }
        }
    }

    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%.4f\t", forward[i][0]);
        for (int j = 1; j < n - i - 1; j++) {
            printf("%.4f\t", forward[i][j]);
        }
        printf("\n");
    }

    // Applying Newton's Forward Interpolation formula
    float product = 1;
    for (int j = 1; j < n; j++) {
        product *= (u - (j - 1));
        y0 += (product * forward[0][j - 1]) / factorial(j);
    }

    return y0;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n]; // Arrays to store the data points
    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    float x0;
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &x0);

    float result = newtonForwardInterpolation(n, x, y, x0);
    printf("The interpolated value at x = %.4f is: %.4f\n", x0, result);

    return 0;
}
/*
Program execution 1:
Enter the number of data points: 6
Enter the data points (x and y):
x[0] y[0]: 2 5.1
x[1] y[1]: 4 4.2
x[2] y[2]: 6 3.1
x[3] y[3]: 8 3.5
x[4] y[4]: 10 6.2
x[5] y[5]: 12 7.3
Enter the value of x for interpolation: 3

Forward Difference Table:
-0.9000 -0.2000 1.7000  -0.9000 -3.8000
-1.1000 1.5000  0.8000  -4.7000
0.4000  2.3000  -3.9000
2.7000  -1.6000
1.1000
The interpolated value at x = 3.0000 is: 4.7125

Program execution 2:
Enter the number of data points: 5
Enter the data points (x and y):
x[0] y[0]: 1.1
0.968
x[1] y[1]: 2 1.4715
x[2] y[2]: 3.5 2.1287
x[3] y[3]: 5 2.0521
x[4] y[4]: 7.1 1.4480
Enter the value of x for interpolation: 1.75

Forward Difference Table:
0.5035  0.1537  -0.8875 1.0938
0.6572  -0.7338 0.2063
-0.0766 -0.5275
-0.6041
The interpolated value at x = 1.7500 is: 1.2517
*/