#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    char longest_word[50] = "";
    char current_word[50] = "";
    int i, j = 0;

    // Get input string from the user safely
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if appended by fgets
    sentence[strcspn(sentence, "\n")] = '\0';

    for (i = 0; i <= strlen(sentence); i++) {
        // Build the current word if the character is not a space or null terminator
        if (sentence[i] != ' ' && sentence[i] != '\0') {
            current_word[j++] = sentence[i];
        } 
        // Once a space or end of string is encountered, a word is formed
        else {
            current_word[j] = '\0'; // Null-terminate the current word

            // Check if the current word is longer than the previously recorded longest word
            if (strlen(current_word) > strlen(longest_word)) {
                strcpy(longest_word, current_word);
            }
            j = 0; // Reset index for the next word
        }
    }

    // Print the result
    printf("The longest word is: %s\n", longest_word);
    printf("Length of the longest word: %lu\n", strlen(longest_word));

    return 0;
}
