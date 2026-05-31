#include <stdio.h>

int main() {
    int n, i;
    int t1 = 0, t2 = 1;
    int nt;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        
        if (i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", t2);
            continue;
        }
        
        nt = t1 + t2;
        t1 = t2;
        t2 = nt;
        printf("%d, ", nt);
    }
    return 0;
}
