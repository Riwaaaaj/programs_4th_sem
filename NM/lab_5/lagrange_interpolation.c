#include <stdio.h>
#define MAX_SIZE 6

float lagrangeInterpolation(float x[], float y[], int n, float targetX) {
    float result = 0.0;

    for (int i = 0; i < n; ++i) {
        float term = y[i]; // Start with the y[i] value

        // Compute the product of the terms (x - x[j]) / (x[i] - x[j])
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                term *= (targetX - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }
    return result;
}

int main() {
    float x[MAX_SIZE], y[MAX_SIZE], targetX, resultY;
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("Enter x[%d]: ", i + 1);
        scanf("%f", &x[i]);
        printf("Enter y[%d]: ", i + 1);
        scanf("%f", &y[i]);
    }
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &targetX);

    resultY = lagrangeInterpolation(x, y, MAX_SIZE, targetX);

    printf("The interpolated value at x = %.2f is y = %.2f\n", targetX, resultY);
    return 0;
}/*
Program execution 1:

Enter x[1]: 1.1
Enter y[1]: 0.698
Enter x[2]: 2
Enter y[2]: 1.4715
Enter x[3]: 3.5
Enter y[3]: 2.1287
Enter x[4]: 5
Enter y[4]: 2.0521
Enter x[5]: 7.1
Enter y[5]: 1.4480
Enter the value of x for interpolation: 1.75
The interpolated value at x = 1.75 is y = 1.28


When equal interval was given in Lagrange's interpolation.

Program execution 2:
Enter x[1]: 2
Enter y[1]: 5.1
Enter x[2]: 4
Enter y[2]: 4.2
Enter x[3]: 6
Enter y[3]: 3.1
Enter x[4]: 8
Enter y[4]: 3.5
Enter x[5]: 10
Enter y[5]: 6.2
Enter x[6]: 12
Enter y[6]: 7.3
Enter the value of x for interpolation: 11
The interpolated value at x = 11.00 is y = 7.48


Program execution 3:
Enter x[1]: 2
Enter y[1]: 5.1
Enter x[2]: 4
Enter y[2]: 4.2
Enter x[3]: 6
Enter y[3]: 3.1
Enter x[4]: 8
Enter y[4]: 3.5
Enter x[5]: 10
Enter y[5]: 6.2
Enter x[6]: 12
Enter y[6]: 7.3
Enter the value of x for interpolation: 3
The interpolated value at x = 3.00 is y = 4.71

*/