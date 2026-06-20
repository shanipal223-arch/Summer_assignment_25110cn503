#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the square matrix (N x N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int matrix[n][n];
    int total_sum = 0;

    
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        
        total_sum += matrix[i][i];

        
        total_sum += matrix[i][n - 1 - i];
    }

    
    if (n % 2 == 1) {
        int center = n / 2;
        total_sum -= matrix[center][center];
    }

    
    printf("\nTotal Diagonal Sum: %d\n", total_sum);

    return 0;
}
