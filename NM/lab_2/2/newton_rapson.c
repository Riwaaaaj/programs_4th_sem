#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001 //define your error here
double f(double x) {
// Define your function here return x * log10(x) - 1.2;
}
double f_prime(double x) {
// Define the derivative of your function here return 0.43429 + log10(x);
}
double newton_raphson(double x) { double x_next = x;
double fx, fpx;
int iter = 1;
printf("iter\t x\t\t f(x)\n");
while (1) {
    fx = f(x_next);
    fpx = f_prime(x_next);
printf("%d\t%lf\t%lf\n", iter, x_next, fx);
    if (fabs(fx) < EPSILON) {
        break;
}
x_next = x_next - fx/fpx;
iter++;
} // run the loop until break staement is encountered.
    return x_next;
}
int main() {
double root = newton_raphson(2); // Starting initial value for x printf("The root is: %lf", root);
return 0;
}