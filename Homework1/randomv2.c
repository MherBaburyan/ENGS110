#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// I used time.h to constantly generate a new number 
//https://www.geeksforgeeks.org/generating-random-number-range-c/

int main() {
    
    srand(time(0));
    
    // Declaring variables and generating a random number between 1 and 100
    int guess, att = 0, number = rand() % 100 + 1;

    printf("Guess the number between 1 and 100!\n");

    // Constantly asking the user to guess and check if the user guessed or not
    do {//I used a do loop because it guarantees that the code inside the loop executes at least once before checking the condition
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        att = att + 1; // So we can later know how much it took to guess
        
        if (guess < number) {
            printf("Higher\n");
        } else if (guess > number) {
            printf("Lower\n");
        } else {
            printf("Congrats! You guessed the number in %d attempts.\n", att);
        }
    } while (guess != number); // Repeat until the user guesses the number

    return 0;
}
