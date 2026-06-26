#include <stdio.h>

int main() {
    int age;

    // Prompt the user for age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Validate the age input
    if (age < 0) {
        printf("Invalid age entered.\n");
    } 
    // Check if eligible
    else if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } 
    // Not eligible
    else {
        printf("Sorry, you are not eligible to vote yet.\n");
        printf("You must wait %d more year(s) to vote.\n", 18 - age);
    }

    return 0;
}
