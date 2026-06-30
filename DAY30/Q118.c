#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define structure for book information
struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; // 0 = Available, 1 = Issued
};

// Function prototypes
void addBook(struct Book library[], int *bookCount);
void displayBooks(const struct Book library[], int bookCount);
void searchBook(const struct Book library[], int bookCount);
void issueBook(struct Book library[], int bookCount);
void returnBook(struct Book library[], int bookCount);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== MINI LIBRARY SYSTEM MENU ====");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit System");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook(struct Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("\nError: Library space is full!\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter 4-Digit Book ID: ");
    scanf("%d", &newBook.id);
    while (getchar() != '\n'); // Clear newline buffer

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove trailing newline

    newBook.is_issued = 0; // Default status is available

    library[*bookCount] = newBook;
    (*bookCount)++;

    printf("\nSuccess: Book successfully added to inventory!\n");
}

// Function to view all books in inventory
void displayBooks(const struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nThe library inventory is currently empty.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n");
}

// Function to search for a specific book by ID
void searchBook(const struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nThe library inventory is empty.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("\nError: Book with ID %d not found.\n", searchId);
}

// Function to change status to Issued
void issueBook(struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books available to issue.\n");
        return;
    }

    int targetId;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &targetId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            if (library[i].is_issued == 1) {
                printf("\nNotice: This book is already checked out.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nSuccess: Book successfully issued!\n");
            }
            return;
        }
    }
    printf("\nError: Book ID not found.\n");
}

// Function to change status back to Available
void returnBook(struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo records found to handle returns.\n");
        return;
    }

    int targetId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &targetId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            if (library[i].is_issued == 0) {
                printf("\nNotice: This book is already safe in shelves.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nSuccess: Book returned safely to inventory!\n");
            }
            return;
        }
    }
    printf("\nError: Book ID not found.\n");
}
