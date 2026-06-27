#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NUM_SUBJECTS 5

// Structure to hold student details
struct Student {
    int roll_no;
    char name[50];
    int marks[NUM_SUBJECTS];
    int total;
    float percentage;
    char grade[5];
    char status[5];
};

// Function prototypes
void input_student_data(struct Student *s);
void calculate_results(struct Student *s);
void display_marksheet(struct Student s);

// Subject names array for consistency
const char *subject_names[NUM_SUBJECTS] = {
    "Mathematics", 
    "Physics", 
    "Chemistry", 
    "English", 
    "Computer Science"
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0, choice;

    printf("--- STUDENT MARKSHEET GENERATION SYSTEM ---\n");
    printf("Enter the number of students to evaluate (Max %d): ", MAX_STUDENTS);
    scanf("%d", &count);

    if (count <= 0 || count > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;
    }

    // Input loop
    for (int i = 0; i < count; i++) {
        printf("\n=======================================\n");
        printf("Entering Details for Student #%d\n", i + 1);
        printf("=======================================\n");
        input_student_data(&students[i]);
        calculate_results(&students[i]);
    }

    // Display loop / Menu
    while (1) {
        printf("\n================ MENU ================\n");
        printf("1. Display All Marksheets\n");
        printf("2. Search Marksheet by Roll Number\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < count; i++) {
                display_marksheet(students[i]);
            }
        } 
        else if (choice == 2) {
            int search_roll, found = 0;
            printf("\nEnter Roll Number to search: ");
            scanf("%d", &search_roll);

            for (int i = 0; i < count; i++) {
                if (students[i].roll_no == search_roll) {
                    display_marksheet(students[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("\nRecord not found for Roll Number %d.\n", search_roll);
            }
        } 
        else if (choice == 3) {
            printf("\nExiting system. Have a great day!\n");
            break;
        } 
        else {
            printf("\nInvalid selection! Please pick a valid option.\n");
        }
    }

    return 0;
}

// Function to collect student details and marks safely
void input_student_data(struct Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->roll_no);
    
    // Clear input buffer before reading strings
    while (getchar() != '\n'); 
    
    printf("Enter Student Full Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        while (1) {
            printf("Enter marks for %s (0-100): ", subject_names[i]);
            scanf("%d", &s->marks[i]);
            
            if (s->marks[i] >= 0 && s->marks[i] <= 100) {
                break; // Valid input
            }
            printf("Invalid data entry! Marks must remain between 0 and 100.\n");
        }
    }
}

// Function to calculate scores, percentages, grades, and pass/fail metrics
void calculate_results(struct Student *s) {
    s->total = 0;
    int failed_any = 0;

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->total += s->marks[i];
        if (s->marks[i] < 35) { 
            failed_any = 1; // Mark criteria: minimum 35 needed to pass a subject
        }
    }

    s->percentage = (float)s->total / NUM_SUBJECTS;

    // Determine status
    if (failed_any) {
        strcpy(s->status, "FAIL");
        strcpy(s->grade, "F");
    } else {
        strcpy(s->status, "PASS");
        // Grade calculation boundary logic
        if (s->percentage >= 85.0) strcpy(s->grade, "A+");
        else if (s->percentage >= 70.0) strcpy(s->grade, "A");
        else if (s->percentage >= 55.0) strcpy(s->grade, "B");
        else if (s->percentage >= 40.0) strcpy(s->grade, "C");
        else strcpy(s->grade, "D");
    }
}

// Function to generate the formatted terminal marksheet
void display_marksheet(struct Student s) {
    printf("\n\t\tSTATE BOARD ACADEMIC RECORD\n");
    printf("\t===============================================\n");
    printf("\tRoll Number: %-15d Name: %s\n", s.roll_no, s.name);
    printf("\t===============================================\n");
    printf("\t%-25s \t %s\n", "SUBJECT", "MARKS OBTAINED");
    printf("\t-----------------------------------------------\n");
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("\t%-25s \t %d\n", subject_names[i], s.marks[i]);
    }
    
    printf("\t-----------------------------------------------\n");
    printf("\tGRAND TOTAL: %-13d PERCENTAGE: %.2f%%\n", s.total, s.percentage);
    printf("\tFINAL GRADE: %-13s RESULT STATUS: %s\n", s.grade, s.status);
    printf("\t===============================================\n\n");
}
