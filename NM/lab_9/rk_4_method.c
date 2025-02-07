#include <stdio.h>

#define fPrime(x, y) (x + y) // dy/dx = x + y

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
    rungeKutta(0, 1, 3, 0.3);
    return 0;
}
/*
x       y
0.000   1.000
0.100   1.110
0.200   1.243
0.300   1.400
*/