#include <stdio.h>

int main() {
    int rows, cols;
    
  
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols];
    
   
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    
    printf("\n--- Row-wise Sums ---\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum for each new row
        
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; // Add elements of the current row
        }
        
        printf("Sum of elements in Row %d = %d\n", i + 1, rowSum);
    }
    
    return 0;
}
