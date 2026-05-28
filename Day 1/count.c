#include <stdio.h>

int main() {
    int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Keep track of the original number for printing later
    int original_num = num;

    // Handle 0 specifically
    if (num == 0) {
        count = 1;
    }

    // Convert negative numbers to positive
    if (num < 0) {
        num = -num;
    }

    // Simple loop to strip digits one by one
    while (num > 0) {
        num = num / 10; // Eliminates the last digit
        count++;        // Adds 1 to the digit count
    }

    printf("The number %d has %d digits.\n", original_num, count);
    return 0;
}
