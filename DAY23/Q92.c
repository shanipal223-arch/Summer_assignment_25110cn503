#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define ASCII_SIZE 256

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0}; 
    int i, max_count;
    char max_char;

    printf("Enter a string: ");
   
    if (fgets(str, sizeof(str), stdin) != NULL) {
       
        str[strcspn(str, "\n")] = '\0';
    }

    
    for (i = 0; str[i] != '\0'; i++) {
      
        freq[(unsigned char)str[i]]++;
    }

    
    max_count = 0;
    max_char = str[0]; 

    for (i = 0; i < ASCII_SIZE; i++) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_char = (char)i;
        }
    }

    
    if (max_count > 0) {
        printf("Maximum occurring character is '%c' and it appears %d times.\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
