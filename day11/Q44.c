#include <stdio.h>


int getFactorial(int n) {
    int fact = 1;
    
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int num = 5;
    
    
    printf("Factorial of %d is: %d\n", num, getFactorial(num));
    
    return 0;
}
