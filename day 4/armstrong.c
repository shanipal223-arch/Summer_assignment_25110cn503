#include <stdio.h>

int main() {
    int num, origNum, remainder, sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    origNum = num;

    
    while (num > 0) {
        remainder = num % 10;                
        sum += remainder * remainder * remainder; 
        num = num / 10;                        
    }

    
    if (sum == origNum) {
        printf("%d is an Armstrong number.\n", origNum);
    } else {
        printf("%d is not an Armstrong number.\n", origNum);
    }

    return 0;
}
