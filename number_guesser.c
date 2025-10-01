#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define MAX_ATTEMPTS 10

/*
 * Number Guessing Game
 *
 * Generates a random number between MIN_NUMBER and MAX_NUMBER and allows the user
 * to guess the number within MAX_ATTEMPTS attempts. Provides feedback after each
 * guess and tracks the number of attempts taken. Users can choose to play again
 * without restarting the program.
 */

static void clear_input_buffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

static int prompt_for_guess(int attempt)
{
    int guess;
    int result;

    while (1) {
        printf("Attempt %d/%d - Enter your guess (%d-%d): ", attempt, MAX_ATTEMPTS,
               MIN_NUMBER, MAX_NUMBER);

        result = scanf("%d", &guess);
        if (result == 1 && guess >= MIN_NUMBER && guess <= MAX_NUMBER) {
            clear_input_buffer();
            return guess;
        }

        printf("Invalid input. Please enter an integer between %d and %d.\n",
               MIN_NUMBER, MAX_NUMBER);

        if (result != 1) {
            clear_input_buffer();
        }
    }
}

static int play_round(void)
{
    int target = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
    int attempt;

    printf("\nI'm thinking of a number between %d and %d. Can you guess it?\n",
           MIN_NUMBER, MAX_NUMBER);

    for (attempt = 1; attempt <= MAX_ATTEMPTS; ++attempt) {
        int guess = prompt_for_guess(attempt);

        if (guess == target) {
            printf("Congratulations! You guessed the number in %d attempts.\n",
                   attempt);
            return 1;
        }

        if (guess < target) {
            printf("Too low! Try a higher number.\n");
        } else {
            printf("Too high! Try a lower number.\n");
        }
    }

    printf("\nOut of attempts! The correct number was %d. Better luck next time.\n",
           target);
    return 0;
}

int main(void)
{
    char play_again;

    srand((unsigned int)time(NULL));

    printf("Welcome to the Number Guessing Game!\n");

    do {
        play_round();

        printf("\nWould you like to play again? (y/n): ");
        if (scanf(" %c", &play_again) != 1) {
            printf("\nInput error. Exiting the game.\n");
            break;
        }

        play_again = (char)tolower((unsigned char)play_again);
        clear_input_buffer();
    } while (play_again == 'y');

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}
