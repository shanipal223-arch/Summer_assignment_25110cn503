#include <stdio.h>

int main() {
    int lower, upper, i, j, isPrime;

    
    printf("Enter lower bound: ");
    scanf("%d", &lower);
    printf("Enter upper bound: ");
    scanf("%d", &upper);

    printf("Prime numbers: ");

    
    for (i = lower; i <= upper; i++) {
        
        if (i <= 1) {
            continue;
        }

        isPrime = 1; 

        
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0; 
                break;      
            }
        }

        
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
