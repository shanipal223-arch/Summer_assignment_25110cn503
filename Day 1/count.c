#include <stdio.h>

int main() {
    int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    
    int original_num = num;

    
    if (num == 0) {
        count = 1;
    }

    
    if (num < 0) {
        num = -num;
    }

    
    while (num > 0) {
        num = num / 10; 
        count++;        
    }

    printf("The number %d has %d digits.\n", original_num, count);
    return 0;
}
