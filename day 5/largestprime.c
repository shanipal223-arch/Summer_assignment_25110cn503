#include <stdio.h>

int main() {
    long long n = 600851475143; 
    long long i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            n /= i; 
        } else {
            i++;    
        }
    }

    printf("Largest prime factor: %lld\n", n);
    return 0;
}
