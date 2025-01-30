#include <stdio.h>
#include <math.h>

double f(double x) {
    return (4 * exp(x) / (1 + pow(x, 3)));
}

double simpsonsThreeEighthsRule(double a, double b, int n) {
    // if (n % 3 != 0) {
    //     printf("Number of subintervals (n) must be a multiple of 3.\n");
    //     return 0.0;
    // }

    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Sum of first and last terms

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 3 == 0) 
            sum += 2 * f(x); // Coefficient for terms divisible by 3
        else 
            sum += 3 * f(x); // Coefficient for other terms
    }

    return 3.00 * h * sum / 8.00;
}

int main() {
    double a = 0.0; // Lower limit of integration
    double b = 2.0; // Upper limit of integration
    int n = 6;      // Number of subintervals (must be a multiple of 3)

    double result = simpsonsThreeEighthsRule(a, b, n);
    if (result != 0.0)
        printf("Numerical integration result: %lf\n", result);

    return 0;
}
/*
Output 1 (for cos(x) and n = 66):(Multiple of 3)
Numerical integration result: -0.700351 (Exact ans: -0.7004)

Output 2 (for cos(x) and n = 5):(Not a multiple of 3)
Numerical integration result: -0.655360 (Exact ans: -0.7004)

Output 3 (for cos(x) and n = 17):(Not a multiple of 3)
Numerical integration result: -0.686072 (Exact ans: -0.7004)

Output 4 (4 * exp(x) / (1 + pow(x, 3))) and n = 6):
Numerical integration result: 9.641198 (Exact ans: 9.626)
*/