#include <stdio.h>

int main() {
    int score = 0;
    char answer;

    printf("=== WELCOME TO THE C QUIZ ===\n\n");

    // Question 1
    printf("1. What is the correct file extension for a C source file?\n");
    printf("A. .cpp\nB. .c\nC. .h\nD. .exe\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is B.\n\n");
    }

    // Question 2
    printf("2. Which function prints output to the screen?\n");
    printf("A. scanf\nB. print\nC. printf\nD. output\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is C.\n\n");
    }

    // Question 3
    printf("3. What is the starting index of an array in C?\n");
    printf("A. -1\nB. 1\nC. 0\nD. 2\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is C.\n\n");
    }

    // Final Score
    printf("=== QUIZ OVER ===\n");
    printf("Your Final Score: %d out of 3\n", score);

    return 0;
}
