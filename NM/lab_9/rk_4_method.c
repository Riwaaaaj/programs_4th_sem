#include <stdio.h>

#define fPrime(x, y) (x + y * y)

void rungeKutta(double x0, double y0, double n, double xn) {
    double h = (xn - x0) / n; 
    double x = x0, y = y0;

    printf("x\ty\n");
    printf("%.3f\t%.3f\n", x, y);
    
    double k1, k2, k3, k4, k;
    for (int i = 0; i < n; i++) {
        k1 = h * fPrime(x, y);
        k2 = h * fPrime(x + h / 2, y + k1 / 2);
        k3 = h * fPrime(x + h / 2, y + k2 / 2);
        k4 = h * fPrime(x + h, y + k3);
        
        k = (k1 + 2 * (k2 + k3) + k4) / 6;
        y = y + k;
        x = x + h;

        printf("%.3f\t%.3f\n", x, y);
    }
}

int main() {
    rungeKutta(0, 1, 1, 0.2);
    return 0;
}
/*
Output when n = 1, f'(x) = x + y, y(0) = 1 at x = 0.3
x       y
0.000   1.000
0.300   1.400

Output when n = 2, f'(x) = x + y * y, y(0) = 1 at x = 0.2
x       y
0.000   1.000
0.100   1.116
0.200   1.273

Output when n = 1, f'(x) = x + y * y, y(0) = 1 at x = 0.2
x       y
0.000   1.000
0.200   1.269
*/