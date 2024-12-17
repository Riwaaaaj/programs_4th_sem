#include <stdio.h>
#define N 3 
int main() {
  float A[N][N+1] = { {3, 4, 5, 40}, 
                      {1, 1, 1, 9},
                      {2, -3, 4, 13} };
  for (int k = 0; k < N; k++) { //selecting the row
    for (int i = k+1; i < N; i++) {
      float f = A[i][k] / A[k][k]; //finding the factor for row operation to make 0. 
      for (int j = k; j <= N; j++) {
        A[i][j] = A[i][j] - f * A[k][j];// row operation for 2nd row and so on. 
      }
    }
  }
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
    float x[N];
    for (int i = N-1; i >= 0; i--) {
      x[i] = A[i][N]; //holding the constant term after the gauss elimination. 
      for (int j = i+1; j < N; j++) {
          x[i] = x[i] - A[i][j] * x[j];
      }
      x[i] /= A[i][i];
  }
  printf("Solution:\n");
  for (int i = 0; i < N; i++) {
    printf("x%d = %.2f\n", i, x[i]); 
  }
  return 0; 
}
/*
Upper Triangular Matrix:
3.00    4.00    5.00    40.00
0.00    -0.33   -0.67   -4.33
0.00    -0.00   12.00   60.00
Solution:
x0 = 1.00
x1 = 3.00
x2 = 5.00
*/