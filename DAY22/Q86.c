#include <stdio.h>
#include <ctype.h> // Required for isspace()

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; 

    while (*str) {
       
        if (isspace((unsigned char)*str)) {
            in_word = 0; // Left the word
        } 
        
        else if (in_word == 0) {
            in_word = 1; 
            count++;     
        }
        str++; 
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("Total number of words: %d\n", words);
    }

    return 0;
}
