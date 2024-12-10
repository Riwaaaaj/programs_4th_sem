#include <stdio.h>
#define N 3 // number of variables int main() {
// creating an 2D ARRAY with N rows and N+1 coloumns
float A[N][N + 1] = {{3, 4, 5, 40}, {1, 1, 1, 9}, {2, -3, 4, 13}};
// Gaussian elimination
for (int k = 0; k < N; k++) { // selecting the row
  for (int i = k + 1; i < N; i++) {
    float f = A[i][k] / A[k][k]; // finding the factor for row operation to make
                                 // 0. for (int j = k+1; j <= N; j++) {
    A[i][j] = A[i][j] - f * A[k][j]; // row operation for 2nd row and so on. }
    A[i][k] = 0; // making 1,2 of 1st column 0. you can also remove it. }
  }
  // Backward substitution
  float x[N];
  for (int i = N - 1; i >= 0; i--) {
    x[i] = A[i][N]; // holding the constant term after the gauss elimination.
                    // for (int j = i+1; j < N; j++) {
    x[i] = x[i] - A[i][j] * x[j];
  }
  x[i] = x[i] / A[i][i];
}
// Print solution
printf("Solution:\n");
for (int i = 0; i < N; i++) {
  printf("x%d = %f\n", i, x[i]);
}
return 0;
}