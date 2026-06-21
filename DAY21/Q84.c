#include <stdio.h>

int main() {
    char lowerChar;
    char upperChar;

   
    printf("Enter a lowercase character: ");
    scanf("%c", &lowerChar);

   
    if (lowerChar >= 'a' && lowerChar <= 'z') {
        
        upperChar = lowerChar - 32;
        printf("The uppercase equivalent is: %c\n", upperChar);
    } else {
        printf("Error: That is not a lowercase character.\n");
    }

    return 0;
}
