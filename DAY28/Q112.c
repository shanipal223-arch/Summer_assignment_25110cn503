#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

// Define contact structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
} Contact;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("=================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clear newline character left by scanf

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to clear stdin buffer to prevent input skipping
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Create Operation: Add a new contact
void addContact() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact c;
    printf("\nEnter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = '\0';

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);

    printf("\nContact added successfully!\n");
}

// 2. Read Operation: Display all contacts
void displayContacts() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read binary mode
    if (fp == NULL) {
        printf("\nNo contacts found. Register some contacts first!\n");
        return;
    }

    Contact c;
    int count = 1;
    printf("\n=================================================================================\n");
    printf("%-5s %-20s %-15s %-25s %-20s\n", "S.No", "Name", "Phone", "Email", "Address");
    printf("=================================================================================\n");

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        printf("%-5d %-20s %-15s %-25s %-20s\n", count++, c.name, c.phone, c.email, c.address);
    }
    
    if(count == 1) {
        printf("No records found in file.\n");
    }
    printf("=================================================================================\n");
    fclose(fp);
}

// 3. Read/Query Operation: Search contact by name
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo data found inside file!\n");
        return;
    }

    char searchName[50];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        // Case-insensitive comparison can be used, using standard strcmp here
        if (strcasecmp(c.name, searchName) == 0) { 
            if (!found) {
                printf("\nContact Found:\n");
                printf("----------------------------------------\n");
            }
            printf("Name   : %s\n", c.name);
            printf("Phone  : %s\n", c.phone);
            printf("Email  : %s\n", c.email);
            printf("Address: %s\n\n", c.address);
            found = 1;
        }
    }

    if (!found) {
        printf("\nContact matching '%s' not found.\n", searchName);
    }
    fclose(fp);
}

// 4. Update Operation: Modify details of an existing contact
void updateContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to update.\n");
        return;
    }

    char targetName[50];
    printf("\nEnter the name of the contact to update: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    // Open a temporary file to write modified data
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary storage!\n");
        fclose(fp);
        return;
    }

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcasecmp(c.name, targetName) == 0) {
            found = 1;
            printf("\n--- Contact Found. Enter New Details ---\n");
            
            printf("Enter New Name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = '\0';

            printf("Enter New Phone Number: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = '\0';

            printf("Enter New Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = '\0';

            printf("Enter New Address: ");
            fgets(c.address, sizeof(c.address), stdin);
            c.address[strcspn(c.address, "\n")] = '\0';
        }
        fwrite(&c, sizeof(Contact), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("\nContact updated successfully!\n");
    } else {
        remove("temp.dat");
        printf("\nContact matching '%s' not found.\n", targetName);
    }
}

// 5. Delete Operation: Remove contact permanently
void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    char targetName[50];
    printf("\nEnter the name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary storage!\n");
        fclose(fp);
        return;
    }

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcasecmp(c.name, targetName) == 0) {
            found = 1; // Skip writing this contact to the temp file
            continue;
        }
        fwrite(&c, sizeof(Contact), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("\nContact deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("\nContact matching '%s' not found.\n", targetName);
    }
}
