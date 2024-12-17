#include <stdio.h>
#include <math.h>
#define N 3 // size of the system
int main() {
  float A[N][N+1] = { {3, 4,5, 40},
                      {1, 1, 1, 9},
                      {2,-3, 4, 13} };
  float x[N];
  int i, j, k;
  float max, temp, f;

  // Gaussian elimination with partial pivoting
  for (k = 0; k < N; i++) {
    max = fabs(A[k][k]);
    int max_row = k;
    // find the row with the largest pivot element 
    for (j = k+1; j < N; j++) {
      if (fabs(A[j][k]) > max) {
          max = fabs(A[j][k]);
          max_row = j;
      } 
    }
  // swap the current row with the row with the largest pivot element
  if (max_row != k) {
    for (i = 0; i < N+1; i++) {
      temp = A[k][i];
      A[k][i] = A[max_row][i];
      A[max_row][i] = temp;
    } 
  }
  // perform Gaussian elimination
  for (i = k+1; i< N; i++) { 
    f = A[i][k] / A[k][k]; 
    for (j = k; j <= N; j++) {
        A[i][j] -= f * A[k][j];
    }
  } 
  }

  // perform back-substitution to solve for the variables
  for (i = N-1; i >= 0; i--) { 
    x[i] = A[i][N];
    for (j = i+1; j < N; j++) { 
      x[i] -= A[i][j] * x[j];
    }
    x[i] /= A[i][i];
  }
  // Print the solution
  printf("Solution:\n"); 
  for (i = 0; i < N; i++) {
    printf("x[%d] = %.2f\n", i, x[i]); 
  }
  return 0; 
}