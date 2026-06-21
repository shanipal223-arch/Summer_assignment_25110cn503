#include <stdio.h>
#include <ctype.h> 

int main() {
    char str[200];
    int vowels = 0;
    int consonants = 0;

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    for (int i = 0; str[i] != '\0'; i++) {
       
        char ch = tolower(str[i]);

        
        if (isalpha(ch)) {
            // Check if it is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } 
           
            else {
                consonants++;
            }
        }
    }

    
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);

    return 0;
}
