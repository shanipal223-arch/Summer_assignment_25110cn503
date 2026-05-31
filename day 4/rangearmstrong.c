#include <stdio.h>

int main() {
    int lower, upper, num, originalNum, digit, sum;

    
    printf("Enter lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Armstrong numbers: ");
    for (num = lower; num <= upper; num++) {
        originalNum = num;
        sum = 0;

        
        while (originalNum > 0) {
            digit = originalNum % 10;
            sum += (digit * digit * digit); 
            originalNum /= 10;
        }

        
        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}
