#include <stdio.h>

// Tabulated data points
double x[] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6}; // x values
double y[] = {7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031}; // y values

// Numerical differentiation using forward difference
double backwardDifference(int index) {
  double h = x[index + 1] - x[index];
  return (3 * y[index] - 4 * y[index - 1] + y[index - 2]) / (2 * h);
}

int main() {
  int index = 5; 
  double result = backwardDifference(index); 
  printf("Numerical differentiation result at x = %.1f: %.4lf\n", x[index], result);

  return 0;
}
/*
Output:
Numerical differentiation result at x = 1.5: 2.8750
*/