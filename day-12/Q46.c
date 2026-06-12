#include <stdio.h>

int isArmstrong(int num) {
    int original = num, sum = 0, remainder;

    while (num > 0) {
        remainder = num % 10;
        sum += remainder * remainder * remainder; 
        num /= 10;
    }

    return (sum == original);
}

int main() {
    if (isArmstrong(153)) {
        printf("Armstrong number\n");
    } else {
        printf("Not an Armstrong number\n");
    }
    return 0;
}
