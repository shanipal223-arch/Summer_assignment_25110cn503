#include <stdio.h>
#include <string.h>

// Helper function to safely read strings with spaces and strip the trailing newline
void read_string(char str[], int size) {
    fgets(str, size, stdin);
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char str1[200], str2[100];
    int choice;

    while (1) {
        // Display System Menu
        printf("\n=================================");
        printf("\n   STRING OPERATIONS SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Find Length of String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Strings");
        printf("\n4. Compare Strings");
        printf("\n5. Reverse String");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        // Read user choice and handle trailing newline buffer
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        while (getchar() != '\n'); // Clear the trailing newline left by scanf

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                read_string(str1, sizeof(str1));
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                read_string(str1, sizeof(str1));
                strcpy(str2, str1);
                printf("Successfully copied! Destination string: \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter the base string (String 1): ");
                read_string(str1, sizeof(str1));
                printf("Enter string to append (String 2): ");
                read_string(str2, sizeof(str2));
                
                // Safety check to prevent buffer overflow before concatenation
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string: \"%s\"\n", str1);
                } else {
                    printf("Error: Combined string size exceeds allocated memory.\n");
                }
                break;

            case 4:
                printf("\nEnter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string: ");
                read_string(str2, sizeof(str2));
                
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Result: Both strings are identical.\n");
                } else if (cmp > 0) {
                    printf("Result: First string is lexicographically greater than the second.\n");
                } else {
                    printf("Result: Second string is lexicographically greater than the first.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                read_string(str1, sizeof(str1));
                
                int len = strlen(str1);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting System. Thank you!\n");
                return 0;

            default:
                printf("\nInvalid selection! Please pick a choice between 1 and 6.\n");
        }
    }
    return 0;
}
