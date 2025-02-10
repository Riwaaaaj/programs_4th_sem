#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10     // Maximum size of the grid
#define MAX_ITER 1000   // Maximum number of iterations
#define EPSILON 1e-5    // Convergence criterion

// Function to solve the Laplace equation using the finite difference method
void solveLaplace(int rows, int cols) {
    if (rows <= 2 || cols <= 2 || rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Invalid grid size. Please provide valid dimensions.\n");
        return;
    }

    double grid[MAX_SIZE][MAX_SIZE];
    double maxDifference;
    int iteration = 0;

    // Initialize the grid with user-provided values
    printf("Enter the values for the grid points:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter the value for grid point (%d, %d): ", i, j);
            scanf("%lf", &grid[i][j]);
        }
    }

    // Perform iterations until convergence or maximum number of iterations is reached
    do {
        maxDifference = 0.0;

        // Update the interior points
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                double old_value = grid[i][j];
                grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
                double difference = fabs(old_value - grid[i][j]);
                if (difference > maxDifference) {
                    maxDifference = difference;
                }
            }
        }
        iteration++;
    } while (maxDifference > EPSILON && iteration < MAX_ITER);

    // Print the final solution
    printf("Iterations: %d\n", iteration);
    printf("Final solution:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\t%0.2f", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of grid points along the x-axis (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    
    printf("Enter the number of grid points along the y-axis (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    solveLaplace(rows, cols);

    return 0;
}
/*
Enter the number of grid points along the x-axis (max 10): 4
Enter the number of grid points along the y-axis (max 10): 4
Enter the values for the grid points:
Enter the value for grid point (0, 0): 1000
Enter the value for grid point (0, 1): 1000
Enter the value for grid point (0, 2): 1000
Enter the value for grid point (0, 3): 1000
Enter the value for grid point (1, 0): 2000
Enter the value for grid point (1, 1): 1000
Enter the value for grid point (1, 2): 625
Enter the value for grid point (1, 3): 500
Enter the value for grid point (2, 0): 2000
Enter the value for grid point (2, 1): 875
Enter the value for grid point (2, 2): 375
Enter the value for grid point (2, 3): 0
Enter the value for grid point (3, 0): 1000
Enter the value for grid point (3, 1): 500
Enter the value for grid point (3, 2): 0
Enter the value for grid point (3, 3): 0
Iterations: 14
Final solution:
1000.00         1000.00         1000.00         1000.00 
2000.00         1208.33         791.67          500.00 
2000.00         1041.67         458.33          0.00 
1000.00         500.00          0.00            0.00
*/