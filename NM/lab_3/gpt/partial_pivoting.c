#include <stdio.h>
#include <math.h>

#define N 3 // Number of variables

/*
This program performs Gauss Elimination with Partial Pivoting to solve
a system of linear equations. It includes forward elimination, partial pivoting,
and back substitution.
*/

void swap_rows(float A[N][N + 1], int row1, int row2) {
    // Function to swap two rows of the matrix
    for (int j = 0; j < N + 1; ++j) {
        float temp = A[row1][j];
        A[row1][j] = A[row2][j];
        A[row2][j] = temp;
    }
}

int main() {
    // Define the augmented matrix
    float A[N][N + 1] = { {3, 4, 5, 40},   // Equation 1: 3x + 4y + 5z = 40
                          {1, 1, 1, 9},    // Equation 2: x + y + z = 9
                          {2, -3, 4, 13} };// Equation 3: 2x - 3y + 4z = 13

    // Perform Gauss Elimination with Partial Pivoting
    for (int k = 0; k < N - 1; ++k) {
        // Partial pivoting: Find the row with the largest absolute value in column k
        int max_row = k;
        for (int i = k + 1; i < N; ++i) {
            if (fabs(A[i][k]) > fabs(A[max_row][k])) {
                max_row = i;
            }
        }

        // Swap rows if necessary
        if (max_row != k) {
            swap_rows(A, k, max_row);
        }

        // Eliminate entries below the pivot
        for (int i = k + 1; i < N; ++i) {
            float factor = A[i][k] / A[k][k];
            for (int j = 0; j < N + 1; ++j) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    printf("Upper Triangular Matrix after Partial Pivoting:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }

    // Back substitution to find the solution
    float x[N]; // Solution array
    for (int i = N - 1; i >= 0; --i) {
        x[i] = A[i][N]; // Start with the constant term
        for (int j = i + 1; j < N; ++j) { // Subtract known variable terms
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i]; // Divide by the diagonal element to get the solution
    }

    // Print the solution
    printf("\nSolution:\n");
    for (int i = 0; i < N; ++i) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}