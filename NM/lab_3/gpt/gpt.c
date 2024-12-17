#include <stdio.h>

void gaussElimination(float a[3][4], float *x, float *y, float *z) {
    int i, j, k;
    float factor;

    // Forward Elimination
    for (i = 0; i < 3; i++) {
        // Make diagonal element 1
        if (a[i][i] == 0) {
            printf("Mathematical Error: Division by zero!\n");
            return;
        }

        for (j = i + 1; j < 3; j++) {
            factor = a[j][i] / a[i][i];
            for (k = i; k < 4; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Back Substitution
    *z = a[2][3] / a[2][2];
    *y = (a[1][3] - a[1][2] * (*z)) / a[1][1];
    *x = (a[0][3] - a[0][2] * (*z) - a[0][1] * (*y)) / a[0][0];
}

int main() {
    float a[3][4], x, y, z;
    int i, j;

    // Input the augmented matrix
    printf("Enter the coefficients of the augmented matrix (3x4):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussElimination(a, &x, &y, &z);

    printf("Solution:\n");
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.2f\n", z);

    return 0;
}