#include <stdio.h>

int main() {
    int pin = 1234;
    int entered_pin;
    int choice;
    float balance = 5000.0;
    float amount;

    printf("=== ATM SIMULATION ===\n");
    printf("Enter 4-digit PIN: ");
    scanf("%d", &entered_pin);

    // Basic security check
    if (entered_pin != pin) {
        printf("Incorrect PIN. System locked.\n");
        return 0; 
    }

    // Main interaction loop
    while (1) {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thank you for using the ATM. Goodbye!\n");
            break; // Exits the loop
        }

        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: $");
                scanf("%f", &amount);
                balance += amount;
                printf("$%.2f deposited successfully.\n", amount);
                break;

            case 3:
                printf("Enter withdrawal amount: $");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Error: Insufficient funds!\n");
                } else {
                    balance -= amount;
                    printf("$%.2f withdrawn successfully.\n", amount);
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
