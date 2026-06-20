#include <stdio.h>

int main() {
    int rows, cols;


    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    
    int original[rows][cols];
    int transposed[cols][rows];

    
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }

    
    printf("\n--- Original Matrix ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", original[i][j]);
        }
        printf("\n");
    }

    
    printf("\n--- Transposed Matrix ---\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
