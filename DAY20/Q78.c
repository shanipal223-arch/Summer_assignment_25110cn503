#include <stdio.h>
#include <stdbool.h>

#define MAX 100


bool isSymmetric(int mat[MAX][MAX], int r, int c) {
    // A symmetric matrix must be square
    if (r != c) {
        return false;
    }

    
    for (int i = 0; i < r; i++) {
        for (int j = i + 1; j < c; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    int matrix[MAX][MAX];
    int rows, cols;

   
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

  
    if (rows > MAX || cols > MAX || rows <= 0 || cols <= 0) {
        printf("Invalid dimensions. Please use sizes between 1 and %d.\n", MAX);
        return 1;
    }

   
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    if (isSymmetric(matrix, rows, cols)) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is NOT symmetric.\n");
    }

    return 0;
}
