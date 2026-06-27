#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.txt"

// Structure defining employee attributes
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function declarations
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
int checkDuplicateId(int id);

int main() {
    int choice;

    while (1) {
        printf("\n=========================================");
        printf("\n       EMPLOYEE MANAGEMENT SYSTEM        ");
        printf("\n=========================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n=========================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type! Exiting system.\n");
            break;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to check if an ID already exists in the file
int checkDuplicateId(int id) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) return 0; // File doesn't exist yet, so no duplicate possible

    Employee emp;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == id) {
            fclose(fp);
            return 1; // Duplicate found
        }
    }
    fclose(fp);
    return 0; // Unique ID
}

// Function to add a new employee
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("\nError opening database file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &emp.id);

    if (checkDuplicateId(emp.id)) {
        printf("\nError: Employee ID %d already exists!\n", emp.id);
        fclose(fp);
        return;
    }

    printf("Enter Employee Name: ");
    getchar(); // Clear trailing newline from buffer
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Save record as comma-separated values (CSV style)
    fprintf(fp, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// Function to print all employee records
void displayAllEmployees() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found. Please add an employee first.\n");
        return;
    }

    Employee emp;
    int count = 0;

    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n--------------------------------------------------------------");
    
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        printf("\n%-10d %-20s %-20s %-10.2f", emp.id, emp.name, emp.designation, emp.salary);
        count++;
    }
    printf("\n--------------------------------------------------------------");
    printf("\nTotal Employees: %d\n", count);
    
    fclose(fp);
}

// Function to find an employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo database file found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    Employee emp;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == searchId) {
            printf("\n--- Employee Found ---");
            printf("\nID          : %d", emp.id);
            printf("\nName        : %s", emp.name);
            printf("\nDesignation : %s", emp.designation);
            printf("\nSalary      : %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// Function to modify details of an employee
void modifyEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo database file found.\n");
        return;
    }

    // Create a temporary file to clone the modified records
    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("\nError processing data modification!\n");
        fclose(fp);
        return;
    }

    int modifyId, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &modifyId);

    Employee emp;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == modifyId) {
            found = 1;
            printf("\nCurrent Details: %s | %s | %.2f", emp.name, emp.designation, emp.salary);
            
            printf("\nEnter New Name: ");
            getchar(); // Buffer flush
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
        }
        fprintf(tempFp, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }

    fclose(fp);
    fclose(tempFp);

    // Swap files
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("\nRecord updated successfully!\n");
    } else {
        printf("\nEmployee ID %d not found.\n", modifyId);
    }
}

// Function to delete an employee record
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo database file found.\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("\nError processing deletion!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    Employee emp;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == deleteId) {
            found = 1; // Skip writing this entry into the temporary file
            continue;
        }
        fprintf(tempFp, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nEmployee ID %d not found.\n", deleteId);
    }
}
