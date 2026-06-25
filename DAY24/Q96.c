#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    // Array to keep track of visited ASCII characters (initialized to 0)
    int visited[256] = {0}; 
    
    int readIndex = 0;
    int writeIndex = 0;

    // Traverse the input string
    while (str[readIndex] != '\0') {
        unsigned char currentChar = str[readIndex];

        // If the character has not been seen yet
        if (visited[currentChar] == 0) {
            visited[currentChar] = 1;       // Mark it as seen
            str[writeIndex] = str[readIndex]; // Copy to the writing position
            writeIndex++;
        }
        readIndex++;
    }

    // Explicitly add the null terminator to finish the unique string
    str[writeIndex] = '\0';
}

int main() {
    // Duplicate test cases
    char text[] = "programming language";

    printf("Original String: %s\n", text);

    // Call the function to modify the string in-place
    removeDuplicates(text);

    printf("String after removing duplicates: %s\n", text);

    return 0;
}
