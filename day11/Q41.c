#include <stdio.h>

float findSum(float num1, float num2) {
    return num1 + num2;
}

int main() {
    float number1, number2, result;

    
    printf("Enter first number: ");
    scanf("%f", &number1);

    
    printf("Enter second number: ");
    scanf("%f", &number2);

    result = findSum(number1, number2);

    printf("The sum is: %.2f\n", result);

    return 0;
}
