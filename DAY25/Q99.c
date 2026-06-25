#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    
    // Maximum 50 names, each with a maximum length of 50 characters
    char names[50][50], temp[50];

    printf("Enter the number of names: ");
    scanf("%d", &n);

    // Consume the newline character left in the buffer by scanf
    getchar(); 

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        // Read names including spaces if necessary (removes newline character)
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; 
    }

    // Bubble Sort logic to sort names alphabetically
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            // If the first name is alphabetically greater than the second name
            if (strcmp(names[i], names[j]) > 0) {
                // Swap the names using strcpy
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Displaying the sorted list
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
