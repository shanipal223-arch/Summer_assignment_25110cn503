#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Global variables to track the employee database
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void menu();

int main() {
    int choice;
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Display the user menu interface
void menu() {
    printf("\n=================================");
    printf("\n    EMPLOYEE MANAGEMENT SYSTEM   ");
    printf("\n=================================");
    printf("\n1. Add Employee");
    printf("\n2. Display All Employees");
    printf("\n3. Search Employee by ID");
    printf("\n4. Delete Employee Record");
    printf("\n5. Exit");
    printf("\n=================================\n");
}

// Add a unique employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nDatabase Full! Cannot add more employees.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    // Check if Employee ID already exists
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Error: Employee ID %d already exists!\n", id);
            return;
        }
    }

    employees[employeeCount].id = id;
    
    // Clear newline character left by scanf
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
    employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = 0; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(employees[employeeCount].designation, sizeof(employees[employeeCount].designation), stdin);
    employees[employeeCount].designation[strcspn(employees[employeeCount].designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &employees[employeeCount].salary);

    employeeCount++;
    printf("\nEmployee recorded successfully!\n");
}

// Display all stored employees
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n------------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-25s %-20s $%-9.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

// Locate an employee using their ID
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found Details:");
            printf("\n-----------------------");
            printf("\nID          : %d", employees[i].id);
            printf("\nName        : %s", employees[i].name);
            printf("\nDesignation : %s", employees[i].designation);
            printf("\nSalary      : $%.2f\n", employees[i].salary);
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", id);
}

// Remove an employee record by shifting array positions
void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            // Shift remaining records forward
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("\nRecord deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}
