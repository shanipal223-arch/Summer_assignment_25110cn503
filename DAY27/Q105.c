#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

// Structure to hold student details
typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;

// Function prototypes
void addStudent();
void displayAll();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// 1. Add a new student record to the file
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append binary mode
    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); // Clear trailing newline character

    printf("Enter Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Course/Branch: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    // Write structure block directly to binary file
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

// 2. Read and display all student records from the file
void displayAll() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read binary mode
    if (fp == NULL) {
        printf("\nNo records found. The database is empty.\n");
        return;
    }

    Student s;
    printf("\n---------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("---------------------------------------------------------\n");

    // Read blocks sequentially until End of File (EOF)
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-20s %-15s %-5.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    printf("---------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific student record using their Roll Number
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int search_roll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == search_roll) {
            printf("\nRecord Found!\n");
            printf("Roll Number : %d\n", s.roll_no);
            printf("Name        : %s\n", s.name);
            printf("Course      : %s\n", s.course);
            printf("GPA         : %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found for Roll Number %d.\n", search_roll);
    }
    fclose(fp);
}

// 4. Delete a student record by moving records to a temporary file
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int delete_roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &delete_roll);

    // Create a temporary file to store records we want to keep
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == delete_roll) {
            found = 1; // Skip writing this record to the temp file
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(FILE_NAME);             // Delete old file
        rename("temp.dat", FILE_NAME); // Rename temp file to replace original
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temp file if nothing changed
        printf("Record not found.\n");
    }
}
