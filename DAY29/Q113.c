#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Display the interactive menu
        printf("\n=============================\n");
        printf("    MENU-DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Exit immediately if the user chooses option 5
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Validate choice before asking for numerical operands
        if (choice < 1 || choice > 5) {
            printf("Error: Invalid choice! Please select an option between 1 and 5.\n");
            continue;
        }

        // Prompt user for input operands
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Process the arithmetic logic using switch-case
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
                
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
                
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
                
            case 4:
                // Handle division-by-zero error explicitly
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }
        
    } while (choice != 5);

    return 0;
}
