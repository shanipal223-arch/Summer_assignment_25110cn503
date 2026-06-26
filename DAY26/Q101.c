#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>    

int main() {
    int secret_number, guess, attempts = 0;

    // 1. Seed the random number generator with current system time
    srand(time(NULL));

    // 2. Generate a secret number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("=================================\n");
    printf("🎯 WELCOME TO THE GUESSING GAME! 🎯\n");
    printf("=================================\n");
    printf("I have chosen a number between 1 and 100.\n\n");

    // 3. Loop until the user guesses the correct number
    do {
        printf("👉 Enter your guess: ");
        
        // Read input from the player
        if (scanf("%d", &guess) != 1) {
            printf("❌ Invalid input! Please enter a valid integer.\n");
            // Clear buffer to avoid an infinite loop on bad input
            while (getchar() != '\n'); 
            continue;
        }

        attempts++; // Increment the counter

        // 4. Provide hot/cold feedback
        if (guess > secret_number) {
            printf("📉 Too high! Try a smaller number.\n\n");
        } 
        else if (guess < secret_number) {
            printf("📈 Too low! Try a larger number.\n\n");
        } 
        else {
            printf("\n🎉 CONGRATULATIONS! 🎉\n");
            printf("You guessed the magic number %d correctly!\n", secret_number);
            printf("🏆 Total attempts made: %d\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}
