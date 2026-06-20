#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

 
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);


    if (c1 != r2) {
        printf("Error! Column of first matrix must equal row of second.\n");
        return 1;
    }

    int first[r1][c1], second[r2][c2], result[r1][c2];

    
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }

  
    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }

   
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
