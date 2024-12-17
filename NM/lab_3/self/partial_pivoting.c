#include <stdio.h>
#include <math.h>
#define N 3
int main() {
  float A[N][N+1] = { {3, 4,5, 40},
                      {1, 1, 1, 9},
                      {2,-3, 4, 13} };
  float x[N];
  int i, j, k;
  float max, temp, f;

  for (k = 0; k < N; ++k) {
    max = fabs(A[k][k]);
    int maxRow = k;
    for (j = k+1; j < N; ++j) {
      if (fabs(A[j][k]) > max) {
          max = fabs(A[j][k]);
          maxRow = j;
      } 
    }
  if (maxRow != k) {
    for (i = 0; i < N+1; ++i) {
      temp = A[k][i];
      A[k][i] = A[maxRow][i];
      A[maxRow][i] = temp;
    } 
  }
  for (i = k+1; i< N; ++i) { 
    f = A[i][k] / A[k][k]; 
    for (j = k; j <= N; ++j) {
        A[i][j] -= f * A[k][j];
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

  for (i = N-1; i >= 0; --i) { 
    x[i] = A[i][N];
    for (j = i+1; j < N; ++j) { 
      x[i] -= A[i][j] * x[j];
    }
    x[i] /= A[i][i];
  }

  printf("Solution:\n"); 
  for (i = 0; i < N; ++i) {
    printf("x[%d] = %.2f\n", i, x[i]); 
  }
  return 0; 
}
/*
Upper Triangular Matrix:
3.00    4.00    5.00    40.00
0.00    -5.67   0.67    -13.67
0.00    0.00    -0.71   -3.53
Solution:
x[0] = 1.00
x[1] = 3.00
x[2] = 5.00
*/