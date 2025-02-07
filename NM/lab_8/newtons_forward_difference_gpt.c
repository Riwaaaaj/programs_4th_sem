#include <stdio.h>

// Tabulated data points
double x[] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6}; // x values
double y[] = {7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031}; // y values
int n = sizeof(x) / sizeof(x[0]); // Number of data points

// Numerical differentiation using forward difference
double forwardDifference(int index) {
    if (index + 2 >= n) { // Check to avoid out-of-bounds access
        printf("Error: Forward difference cannot be applied at index %d.\n", index);
        return 0;
    }
    double h = x[index + 1] - x[index];
    return (-3 * y[index] + 4 * y[index + 1] - y[index + 2]) / (2 * h);
}

int main() {
    int index = 1; // Derivative is to be found at x = 1.1
    double result = forwardDifference(index);
    
    if (index + 2 < n) { // Ensure valid computation
        printf("Numerical differentiation result at x = %.1f: %.4lf\n", x[index], result);
    }
    
    return 0;
}
