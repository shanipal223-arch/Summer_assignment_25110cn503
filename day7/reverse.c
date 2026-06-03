#include <stdio.h>


void print_reverse(int n) {
    
    if (n == 0) {
        return;
    }
    printf("%d", n % 10);
    print_reverse(n / 10);
}

int main() {
    int input_num = 12345;
    
    printf("Original: %d\n", input_num);
    printf("Reversed: ");
    
    if (input_num == 0) {
        printf("0");
    } else {
        print_reverse(input_num);
    }
    
    printf("\n");
    return 0;
}
