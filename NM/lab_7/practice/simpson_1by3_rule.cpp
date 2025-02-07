#include <stdio.h>
#include <math.h>

double f(double x) {
    return (4 * exp(x) / (1 + pow(x, 3))); 
}

double simpsonsOneThirdRule(double a, double b, int n) {
    if(n % 2 != 0) {
      printf("The number must be even! \n");
      return 0.0;
    }

    double sum = f(a) + f(b);
    double h = (b - a) / n;

    for(int i = 1; i < n; ++i) {
      if(n % 2 == 0) {
        sum+= 2.0 * (f(a + i * h));
      } else {
        sum+= 4.0 * (f(a + i * h));
      }
    }

    return h * sum / 3.0;
}

double simpsonsThreeEightsRule(double a, double b, int n) {
    if(n % 3 != 0) {
      printf("The number must be a multiple of 3! \n");
      return 0.0;
    }
    
    double sum = f(a) + f(b);
    double h = (b - a) / n;

    for(int i = 1; i < n; ++i) {
      if(n % 3 == 0) {
        sum+= 2.0 * (f(a + i * h));
      } else {
        sum+= 3.0 * (f(a + i * h));
      }
    }

    return h * sum * 3.0 / 8.0;
}

int main() {
    double a = 0.0; // Lower limit of integration
    double b = 2.0; // Upper limit of integration
    int n = 6;      // Number of subintervals (must be even)

    double result = simpsonsOneThirdRule(a, b, n);
    if (result != 0.0) 
        printf("Numerical integration result: %lf\n", result);

    return 0;
}
/*
Output 1 (for cos(x) and n = 66):(Even)
Numerical integration result: -0.700351 (Exact ans: -0.7004)

Output 2 (for cos(x) and n = 5):(Odd)
Numerical integration result: -0.572268 (Exact ans: -0.7004)

Output 3 (for cos(x) and n = 17):(Odd)
Numerical integration result: -0.661854 (Exact ans: -0.7004)

Output 4 (4 * exp(x) / (1 + pow(x, 3))) and n = 6):
Numerical integration result: 9.626126 (Exact ans: 9.626)
*/