#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

// Function prototypes to maintain modular structure
void addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int *count);
void displayStudents(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int count);
void searchStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int count);
void calculateAverage(float marks[], int count);

int main() {
    // 2D Character Array acting as an Array of Strings
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    
    // 1D Arrays for storing associated integer and float values
    int studentRolls[MAX_STUDENTS];
    float studentMarks[MAX_STUDENTS];
    
    int studentCount = 0; 
    int choice;

    do {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Calculate Class Average Mark\n");
        printf("5. Exit Project\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clears the newline character from the input buffer

        switch(choice) {
            case 1:
                addStudent(studentNames, studentRolls, studentMarks, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 4:
                calculateAverage(studentMarks, studentCount);
                break;
            case 5:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose between 1 and 5.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function 1: Adds a student record to the parallel arrays
void addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase Full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Student Name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    // Remove the trailing newline appended by fgets
    names[*count][strcspn(names[*count], "\n")] = '\0'; 

    printf("Enter Roll Number: ");
    scanf("%d", &rolls[*count]);

    printf("Enter Marks: ");
    scanf("%d", &marks[*count]);

    (*count)++; // Increment student tracker count via pointer
    printf("Student added successfully!\n");
}

// Function 2: Iterates through the tracking arrays and prints formatted data
void displayStudents(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s\n", "Roll No", "Student Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", rolls[i], names[i], marks[i]);
    }
}

// Function 3: Searches element within sequential array using linear search logic
void searchStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[], float marks[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int searchRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (rolls[i] == searchRoll) {
            printf("\nRecord Found!\n");
            printf("Name: %s\n", names[i]);
            printf("Roll Number: %d\n", rolls[i]);
            printf("Marks: %.2f\n", marks[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }
}

// Function 4: Accumulates numerical array elements to compute an average metric
void calculateAverage(float marks[], int count) {
    if (count == 0) {
        printf("\nNo marks available to calculate an average.\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += marks[i];
    }

    printf("\nTotal Class Marks: %.2f\n", total);
    printf("Average Class Mark: %.2f\n", total / count);
}

