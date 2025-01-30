#include <stdio.h>
#include <math.h>

double f(double x) {
    return cos(x); 
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = (f(a) + f(b)); // Sum of first and last terms

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += 2 * f(x); // Sum of intermediate terms
    }

    return h * sum / 2.0;
}

int main() {
    double a = 1.0; // Lower limit of integration
    double b = 3.0; // Upper limit of integration
    int n = 6;      // Number of subintervals (must be a multiple of 3)

    double result = trapezoidalRule(a, b, n);
    printf("Numerical integration result: %lf\n", result);

    return 0;
}
/*
Output 1 (4 * exp(x) / (1 + pow(x, 3))) and n = 6):(Small n)
Numerical integration result: 9.578684 (Exact ans: 9.626)

Output 2 (4 * exp(x) / (1 + pow(x, 3))) and n = 2):(Smaller n)
Numerical integration result: 9.078576 (Exact ans: 9.626)

Output 3 (4 * exp(x) / (1 + pow(x, 3))) and n = 50):(Larger n)
Numerical integration result: 9.625478 (Exact ans: 9.626)

Output 4 (for cos(x) and n = 6):
Numerical integration result: -0.693854 (Exact ans: -0.7004)

*/
