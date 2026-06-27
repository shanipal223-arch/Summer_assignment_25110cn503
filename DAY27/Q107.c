#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to hold individual employee salary components
typedef struct {
    int id;
    char name[50];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund deduction
    float tax;          // Tax deduction
    float gross_salary;
    float net_salary;
} Employee;

// Function Prototypes
void addEmployee(Employee emp[], int *count);
void calculateSalary(Employee *emp);
void displayAllEmployees(const Employee emp[], int count);
void searchEmployee(const Employee emp[], int count);
void printPayslip(const Employee *emp);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n     SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee & Compute Salary");
        printf("\n2. Display All Salary Records");
        printf("\n3. Search Employee & Print Payslip");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayAllEmployees(employees, employee_count);
                break;
            case 3:
                searchEmployee(employees, employee_count);
                break;
            case 4:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

// Function to add a new employee record
void addEmployee(Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: System database is full!\n");
        return;
    }

    Employee new_emp;
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &new_emp.id);
    
    // Check for duplicate IDs
    for (int i = 0; i < *count; i++) {
        if (emp[i].id == new_emp.id) {
            printf("\nError: Employee ID %d already exists!\n", new_emp.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    getchar(); // Clear the dangling newline from previous scanf
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Basic Salary ($): ");
    scanf("%f", &new_emp.basic_salary);

    if (new_emp.basic_salary < 0) {
        printf("\nError: Salary cannot be negative!\n");
        return;
    }

    // Automatically calculate payroll metrics based on basic pay
    calculateSalary(&new_emp);

    // Save the record to the array
    emp[*count] = new_emp;
    (*count)++;

    printf("\nRecord added successfully!\n");
}

// Function containing business rules for financial calculations
void calculateSalary(Employee *emp) {
    // Breakdown formulas: Earnings and Deductions
    emp->hra = emp->basic_salary * 0.15f;  // HRA is 15% of Basic Pay
    emp->da = emp->basic_salary * 0.20f;   // DA is 20% of Basic Pay
    emp->pf = emp->basic_salary * 0.12f;   // PF Deduction is 12% of Basic Pay
    
    // Graduated Income Tax Rule
    if (emp->basic_salary > 5000) {
        emp->tax = emp->basic_salary * 0.10f; // 10% Tax if salary is above 5000
    } else {
        emp->tax = emp->basic_salary * 0.05f; // 5% Tax otherwise
    }

    // Gross and Net calculation formulas
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - (emp->pf + emp->tax);
}

// Function to view all employee payroll items in a tabular format
void displayAllEmployees(const Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("%-7s | %-20s | %-10s | %-8s | %-8s | %-8s | %-8s | %-10s\n", 
           "ID", "Name", "Basic", "HRA", "DA", "PF", "Tax", "Net Salary");
    printf(-------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-7d | %-20s | %-10.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10.2f\n", 
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].hra, emp[i].da, emp[i].pf, emp[i].tax, emp[i].net_salary);
    }
    printf("-------------------------------------------------------------------------------------------------\n");
}

// Function to locate an individual record using Employee ID
void searchEmployee(const Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int search_id;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            printPayslip(&emp[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee Record with ID %d not found.\n", search_id);
    }
}

// Function to print a localized, clean payslip representation
void printPayslip(const Employee *emp) {
    printf("\n=========================================");
    printf("\n            SALARY PAYSLIP               ");
    printf("\n=========================================");
    printf("\nEmployee ID   : %d", emp->id);
    printf("\nEmployee Name : %s", emp->name);
    printf("\n-----------------------------------------");
    printf("\nEARNINGS:");
    printf("\n  Basic Salary: $%.2f", emp->basic_salary);
    printf("\n  HRA (15%%)   : $%.2f", emp->hra);
    printf("\n  DA (20%%)    : $%.2f", emp->da);
    printf("\n-----------------------------------------");
    printf("\nDEDUCTIONS:");
    printf("\n  PF (12%%)    : $%.2f", emp->pf);
    printf("\n  Tax         : $%.2f", emp->tax);
    printf("\n-----------------------------------------");
    printf("\nGROSS SALARY  : $%.2f", emp->gross_salary);
    printf("\nTOTAL DEDUCT  : $%.2f", (emp->pf + emp->tax));
    printf("\nNET TAKE-HOME : $%.2f", emp->net_salary);
    printf("\n=========================================\n");
}
