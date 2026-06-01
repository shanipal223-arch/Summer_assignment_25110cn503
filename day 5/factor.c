#include <stdio.h>

int main() {
    int number;


    printf("Enter a positive integer: ");
    scanf("%d", &number);

    printf("Factors of %d are: ", number);
    
    
    for (int i = 1; i <= number; ++i) {
        
        if (number % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
