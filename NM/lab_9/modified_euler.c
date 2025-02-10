#include <stdio.h>
#include <math.h>
#define fPrime(x, y) (x + y * y) // dy/dx = x + y
int main() {
    double xInitial = 0, yInitial = 1, xFinal = 0.2;
    int n = 3;
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
}/*Output when n = 5, f'(x) = x + y, y(0) = 1 at x = 0.3
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
0.300   1.399   1.542   1.621   0.300   1.399   (Correction)
Output when n = 7, f'(x) = x + y, y(0) = 1 at x = 0.3
x       y       slope   aSlope  xN      yN
0.000   1.000   1.000   -       0.043   1.043   (Prediction)
0.043   1.043   1.000   1.043   0.043   1.045   (Correction)
0.043   1.045   1.000   1.044   0.043   1.045   (Correction)

0.043   1.045   1.088   -       0.086   1.091   (Prediction)
0.086   1.091   1.088   1.132   0.086   1.093   (Correction)
0.086   1.093   1.088   1.133   0.086   1.093   (Correction)

0.086   1.093   1.179   -       0.129   1.144   (Prediction)
0.129   1.144   1.179   1.226   0.129   1.146   (Correction)
0.129   1.146   1.179   1.227   0.129   1.146   (Correction)

0.129   1.146   1.274   -       0.171   1.200   (Prediction)
0.171   1.200   1.274   1.323   0.171   1.202   (Correction)
0.171   1.202   1.274   1.324   0.171   1.202   (Correction)

0.171   1.202   1.374   -       0.214   1.261   (Prediction)
0.214   1.261   1.374   1.425   0.214   1.264   (Correction)
0.214   1.264   1.374   1.426   0.214   1.264   (Correction)

0.214   1.264   1.478   -       0.257   1.327   (Prediction)
0.257   1.327   1.478   1.531   0.257   1.329   (Correction)
0.257   1.329   1.478   1.532   0.257   1.329   (Correction)

0.257   1.329   1.586   -       0.300   1.397   (Prediction)
0.300   1.397   1.586   1.642   0.300   1.399   (Correction)
0.300   1.399   1.586   1.643   0.300   1.400   (Correction)
0.300   1.400   1.586   1.643   0.300   1.400   (Correction)
Output when n = 3, f'(x) = x + y * y, y(0) = 1 at x = 0.2 
x       y       slope   aSlope  xN      yN
0.000   1.000   1.000   -       0.067   1.067   (Prediction)
0.067   1.067   1.000   1.102   0.067   1.073   (Correction)
0.067   1.073   1.000   1.110   0.067   1.074   (Correction)
0.067   1.074   1.000   1.110   0.067   1.074   (Correction)

0.067   1.074   1.220   -       0.133   1.155   (Prediction)
0.133   1.155   1.220   1.344   0.133   1.164   (Correction)
0.133   1.164   1.220   1.354   0.133   1.164   (Correction)

0.133   1.164   1.487   -       0.200   1.263   (Prediction)
0.200   1.263   1.487   1.641   0.200   1.273   (Correction)
0.200   1.273   1.487   1.654   0.200   1.274   (Correction)
0.200   1.274   1.487   1.655   0.200   1.274   (Correction)*/