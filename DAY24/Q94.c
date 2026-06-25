#include <stdio.h>
#include <string.h>

// Function to compress the string
void compressString(const char *str, char *result) {
    int n = strlen(str);
    int resIndex = 0;

    for (int i = 0; i < n; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Append the character to the result
        result[resIndex++] = str[i];

        // Append the count only if it is greater than 1
        if (count > 1) {
            // Convert integer count to characters and append to result
            resIndex += sprintf(&result[resIndex], "%d", count);
        }
    }

    // Null-terminate the compressed string
    result[resIndex] = '\0';
}

int main() {
    char inputString[1000];
    char compressedString[2000]; // Allocation for worst-case scenario

    printf("Enter a string to compress: ");
    // Read string including spaces (stops at newline)
    scanf("%999s", inputString); 

    // Perform compression
    compressString(inputString, compressedString);

    // Display the results
    printf("Original String:   %s\n", inputString);
    printf("Compressed String: %s\n", compressedString);

    return 0;
}
