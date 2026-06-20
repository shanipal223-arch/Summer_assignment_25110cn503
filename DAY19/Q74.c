#include <stdio.h>

int main() {
    int rows, cols;


    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix_A[rows][cols];
    int matrix_B[rows][cols];
    int result[rows][cols];

    
    printf("\nEnter elements for Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element A[%d][%d]: ", i, j);
            scanf("%d", &matrix_A[i][j]);
        }
    }

    
    printf("\nEnter elements for Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element B[%d][%d]: ", i, j);
            scanf("%d", &matrix_B[i][j]);
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }

    
    printf("\nResultant Matrix (A - B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
