#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure to store book data
struct Book {
    int id;
    char title[30];
    char author[30];
};

int main() {
    struct Book library[MAX];
    int bookCount = 0;
    int choice, searchId, found;

    while (1) {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book\n2. Display All\n3. Search by ID\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (bookCount < MAX) {
                printf("Enter ID: ");
                scanf("%d", &library[bookCount].id);
                printf("Enter Title (No spaces): ");
                scanf("%s", library[bookCount].title);
                printf("Enter Author (No spaces): ");
                scanf("%s", library[bookCount].author);
                bookCount++;
                printf("Book added successfully!\n");
            } else {
                printf("Library is full!\n");
            }
        } 
        else if (choice == 2) {
            if (bookCount == 0) {
                printf("No books available.\n");
            } else {
                printf("\nID\tTitle\tAuthor\n");
                for (int i = 0; i < bookCount; i++) {
                    printf("%d\t%s\t%s\n", library[i].id, library[i].title, library[i].author);
                }
            }
        } 
        else if (choice == 3) {
            printf("Enter ID to search: ");
            scanf("%d", &searchId);
            found = 0;
            for (int i = 0; i < bookCount; i++) {
                if (library[i].id == searchId) {
                    printf("Found! Title: %s, Author: %s\n", library[i].title, library[i].author);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Book not found.\n");
        } 
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
