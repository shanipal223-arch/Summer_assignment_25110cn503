#include <stdio.h>

int main() {
    int n;
    int a = 0;
    int b = 1;
    int next;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("The Fibonacci term is: %d\n", a);

    return 0;
}
