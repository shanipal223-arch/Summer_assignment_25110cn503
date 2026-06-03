#include <stdio.h>


unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num ;
    printf("enter number");
    scanf("%d",&num);
    printf("The factorial of %d is %llu\n", num, factorial(num));
    return 0;
}
