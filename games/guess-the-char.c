#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to clear the screen
void clearScreen() {
    // Use system specific command to clear the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main() {
    char guess;
    char answer;
    int attempts = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random letter from 'a' to 'z'
    answer = 'a' + (rand() % 26);

    // Game loop
    do {
        clearScreen(); // Clear the screen for each new guess
        printf("Guess the character (a-z): ");
        scanf(" %c", &guess); // Read a single character
        guess = tolower(guess); // Convert to lowercase to standardize

        if (guess < 'a' || guess > 'z') {
            printf("Please enter a valid character from a to z.\n");
        } else if (guess > answer) {
            printf("Too high! Try a lower character.\n");
            attempts++;
        } else if (guess < answer) {
            printf("Too low! Try a higher character.\n");
            attempts++;
        }

        // Wait for a key press before clearing the screen
        printf("Press enter to continue...\n");
        while (getchar() != '\n');

    } while (guess != answer);

    clearScreen(); // Clear the screen when the correct answer is guessed
    printf("Congratulations! You've guessed the right character '%c' in %d attempts.\n", answer, attempts + 1);

    return 0;
}
