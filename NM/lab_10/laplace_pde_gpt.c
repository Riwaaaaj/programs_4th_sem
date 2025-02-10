#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000      // Maximum number of iterations
#define CONVERGENCE 0.0001 // Convergence criterion

void solveLaplace(int rows, int cols) {
    if (rows <= 2 || cols <= 2) {
        printf("Grid size must be greater than 2x2.\n");
        return;
    }

    double grid[rows][cols];
    double newGrid[rows][cols];
    int i, j, iter = 0;
    double maxDiff;

    // Initialize the grid with boundary conditions
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                grid[i][j] = 100.0; // Example boundary condition
            } else {
                grid[i][j] = 0.0; // Interior points initialized to zero
            }
        }
    }

    // Iterative process
    do {
        maxDiff = 0.0;

        for (i = 1; i < rows - 1; i++) {
            for (j = 1; j < cols - 1; j++) {
                newGrid[i][j] = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]);
                
                double diff = fabs(newGrid[i][j] - grid[i][j]);
                if (diff > maxDiff) {
                    maxDiff = diff;
                }
            }
        }

        // Update grid with new values
        for (i = 1; i < rows - 1; i++) {
            for (j = 1; j < cols - 1; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        iter++;
    } while (maxDiff > CONVERGENCE && iter < MAX_ITER);

    // Output final solution
    printf("Solution after %d iterations:\n", iter);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%6.2f ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of grid points along x-axis and y-axis: ");
    scanf("%d %d", &rows, &cols);
    solveLaplace(rows, cols);
    return 0;
}
