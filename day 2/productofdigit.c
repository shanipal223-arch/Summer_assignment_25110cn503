#include <stdio.h>

int main() {
    int num, rem;
    long long product = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    
    if (num == 0) {
        product = 0;
    } else {
        // Process each digit
        while (num != 0) {
            rem = num % 10;
            product *= rem;
            num /= 10;
        }
    }

    printf("Product of the digits: %lld\n", product);
    return 0;
}
