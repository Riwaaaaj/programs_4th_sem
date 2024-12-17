#include <stdio.h>

#define N 3 // Number of variables

int main() {
    float augmentedMatrix[N][N + 1] = { {3, 4, 5, 40},   // Equation 1: 3x + 4y + 5z = 40
                                       {1, 1, 1, 9},    // Equation 2: x + y + z = 9
                                         {2, -3, 4, 13} };// Equation 3: 2x - 3y + 4z = 13

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            float factor = augmentedMatrix[j + 1][i] / augmentedMatrix [i][i];
            printf("Factor = %f\n", factor);
            // for (int k = 0; i < N; ++i) {

            // }
        }
    }

    // printf("Upper Triangular Matrix:\n");
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N + 1; ++j) {
    //         printf("%f\t", augmentedMatrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}