#include <stdio.h>
#include <math.h>
#define fPrime(x, y) (x + y) // dy/dx = x + y
int main() {
    double xInitial = 0, yInitial = 1, xFinal = 0.3;
    int n = 5;
    double h = (xFinal - xInitial) / n;
    double xN = xInitial, yN = yInitial;
    double slope, aSlope, yTemp, yNext, nextSlope;

    printf("x\ty\tslope\taSlope\txN\tyN\n");
    for (int i = 0; i < n; i++) {
        slope = fPrime(xN, yN);
        yTemp = yN + h * slope;
        xN = xN + h;
        yNext = yN + h * slope;
        printf("%.3f \t%.3f \t%.3f \t-\t%.3f \t%.3f \t(Prediction)\n", xN - h, yN, slope, xN, yNext);
        
        while((round(yN * 1000) / 1000) != (round(yNext * 1000) / 1000)) {
            yN = yNext;
            nextSlope = fPrime(xN, yN);
            aSlope = (nextSlope + slope) / 2;
            yNext = yInitial + h * aSlope;
            printf("%.3f \t%.3f \t%.3f \t%.3f\t%.3f \t%.3f \t(Correction)\n", xN, yN, slope, aSlope, xN, yNext);
        }
        yInitial = yN;
        printf("\n");
    }
    return 0;
}/*
x       y       slope   aSlope  xN      yN
0.000   1.000   1.000   -       0.060   1.060   (Prediction)
0.060   1.060   1.000   1.060   0.060   1.064   (Correction)
0.060   1.064   1.000   1.062   0.060   1.064   (Correction)

0.060   1.064   1.124   -       0.120   1.131   (Prediction)
0.120   1.131   1.124   1.187   0.120   1.135   (Correction)
0.120   1.135   1.124   1.189   0.120   1.135   (Correction)

0.120   1.135   1.255   -       0.180   1.210   (Prediction)
0.180   1.210   1.255   1.322   0.180   1.214   (Correction)
0.180   1.214   1.255   1.325   0.180   1.214   (Correction)

0.180   1.214   1.394   -       0.240   1.298   (Prediction)
0.240   1.298   1.394   1.466   0.240   1.302   (Correction)
0.240   1.302   1.394   1.468   0.240   1.302   (Correction)

0.240   1.302   1.542   -       0.300   1.395   (Prediction)
0.300   1.395   1.542   1.618   0.300   1.399   (Correction)
0.300   1.399   1.542   1.621   0.300   1.399   (Correction)*/