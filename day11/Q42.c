#include <stdio.h>

int findMax(int num1, int num2) {
    return (num1 > num2) ? num1 : num2; //ternary operator
}

int main() {
    int a = 45;
    int b = 72;
    int maximum;

    maximum = findMax(a, b);
    
    printf("The maximum between %d and %d is: %d\n", a, b, maximum);
    return 0;
}
