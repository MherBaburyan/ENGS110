#include <stdio.h>
#include <stdlib.h>

int main() {
    // Seed the random number generator with a fixed value
    srand(11);//The number can be anything, I chose 11 because it is the day of my birtday
    
    // Generate a random number between 1 and 100
    int guess, att = 0, number = rand() % 100 + 1;
    

    printf("Guess the number between 1 and 100!\n");

    // Constantly asking the user to guess and check if the user guessed or not
    do {//I used a do loop because it guarantees that the code inside the loop executes at least once before checking the condition
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        att=att + 1; // Increment the attempts counter
        
        if (guess < number) {
            printf("Higher\n");
        } else if (guess > number) {
            printf("Lower\n");
        } else {
            printf("Correct! You guessed the number in %d attempts.\n", att);
        }
    } while (guess != number);

    return 0;
}
