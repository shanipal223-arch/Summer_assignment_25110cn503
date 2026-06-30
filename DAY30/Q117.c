#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure combining character arrays (strings) and regular arrays
struct Student {
    int rollNumber;
    char name[NAME_LENGTH]; // String to store the student's name
    float marks;
};

// Global array to hold student records and a counter
struct Student recordSystem[MAX_STUDENTS];
int studentCount = 0;

// Function to add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nSystem is full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Clear input buffer to handle string scanning safely
    while (getchar() != '\n'); 
    
    printf("Enter Student Name: ");
    // Read string including spaces safely up to the buffer limit
    fgets(newStudent.name, NAME_LENGTH, stdin);
    // Remove newline character appended by fgets
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    // Save the student to our array database
    recordSystem[studentCount] = newStudent;
    studentCount++;
    
    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n", 
               recordSystem[i].rollNumber, 
               recordSystem[i].name, 
               recordSystem[i].marks);
    }
}

// Function to search for a student using their unique Roll Number
void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int searchRoll;
    int found = 0;
    
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < studentCount; i++) {
        if (recordSystem[i].rollNumber == searchRoll) {
            printf("\n--- Student Found ---\n");
            printf("Roll Number: %d\n", recordSystem[i].rollNumber);
            printf("Name       : %s\n", recordSystem[i].name);
            printf("Marks      : %.2f\n", recordSystem[i].marks);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchRoll);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by Roll No");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}
