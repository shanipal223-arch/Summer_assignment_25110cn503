#include <stdio.h>

int main() {
    double base;
    int exp;
    double result = 1.0;

    
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    
    int original_exp = exp;


    int positive_exp = exp;
    if (exp < 0) {
        positive_exp = -exp;
    }

    
    int i = 0;
    while (i < positive_exp) {
        result *= base;
        i++;
    }

    
    if (original_exp < 0) {
        result = 1.0 / result;
    }
    printf("%.2f^%d = %.6f\n", base, original_exp, result);

    return 0;
}
