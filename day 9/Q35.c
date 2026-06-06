#include <stdio.h>

int main() {
    int rows = 5;
    char ch = 'A';

    
    for (int i = 1; i <= rows; i++) {
        
        for (int j = 1; j <= i; j++) {
            printf("%c", ch);
        }
        
        printf("\n");
        ch++;
    }

    return 0;
}
