#include <stdio.h>
#include <string.h>

int main() {
    // 2D array to store up to 100 words, each with a maximum length of 49 characters
    char words[100][50];
    char temp[50];
    int n, i, j;

    // Ask the user for the number of words
    printf("Enter the number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid number of words.\n");
        return 1;
    }

    // Input the words
    printf("Enter %d words:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Bubble Sort algorithm to sort words by length
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Compare lengths using strlen()
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words using strcpy()
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    // Print the sorted words
    printf("\nWords sorted by length:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
