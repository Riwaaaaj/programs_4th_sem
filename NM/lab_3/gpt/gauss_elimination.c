#include <stdio.h>
#define N 3 
int main() {
    float A[N][N + 1] = { {3, 4, 5, 40},   
                          {1, 1, 1, 9},    
                          {2, -3, 4, 13} };
    for (int k = 0; k < N - 1; ++k) { // Iterate over the pivot rows
        for (int i = k + 1; i < N; ++i) { // Rows below the pivot
            float factor = A[i][k] / A[k][k]; // Factor to eliminate A[i][k]
            for (int j = 0; j < N + 1; ++j) {
                A[i][j] -= factor * A[k][j]; // Row operation
            }
        }
    }
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }
    float x[N]; // Solution array
    for (int i = N - 1; i >= 0; --i) { // Start from the last row
        x[i] = A[i][N]; // Start with the constant term
        for (int j = i + 1; j < N; ++j) { // Subtract known variable terms
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i]; // Divide by the diagonal element to get the solution
    }
    printf("\nSolution:\n");
    for (int i = 0; i < N; ++i) {
        printf("x%d = %f\n", i + 1, x[i]);
    }
    return 0;
}
/*Upper Triangular Matrix:
3.000000        4.000000        5.000000        40.000000
0.000000        -0.333333       -0.666667       -4.333334
0.000000        -0.000000       12.000000       60.000004

Solution:
x1 = 0.999999
x2 = 3.000000
x3 = 5.000000
*/