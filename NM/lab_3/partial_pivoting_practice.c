#include <stdio.h>

#define N 3 // Number of variables

/*
This program uses the Gauss Elimination Method to convert an augmented matrix
into an identity form and then solves it using back substitution.
*/

int main() {
    // Define the augmented matrix
    float A[N][N + 1] = { {3, 4, 5, 40},   // Equation 1: 3x + 4y + 5z = 40
                          {1, 1, 1, 9},    // Equation 2: x + y + z = 9
                          {2, -3, 4, 13} };// Equation 3: 2x - 3y + 4z = 13

    // // Perform Gauss Elimination to convert the matrix into an upper triangular form
    // for (int k = 0; k < N - 1; ++k) { // Iterate over the pivot rows
    //     for (int i = k + 1; i < N; ++i) { // Rows below the pivot
    //         float factor = A[i][k] / A[k][k]; // Factor to eliminate A[i][k]
    //         for (int j = 0; j < N + 1; ++j) {
    //             A[i][j] -= factor * A[k][j]; // Row operation
    //         }
    //     }
    // }
/*
    for (int i = 0;i < ; ++i) {
    //   R1 -> R1 / A[0][0]
      A[i][i] = A[i][i] / A[0][0]; // 1 a b c and d
      
      A[][]
    }
*/

    // Print the Identity matrix
    printf("Identity Matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}