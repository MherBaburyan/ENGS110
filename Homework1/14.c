#include <stdio.h>

int main() {
    //Declaring the variables
    int low = 1, high = 100, guess;
    char res;

    printf("Think of a number between 1 and 100\n(h = too high, l = too low, c = correct)\n");

    while (low <= high) {

        guess = (low + high) / 2;  //The code starts the game with the middle number, and later changing the bounds depending on the input
        printf("%d?\n", guess);
        scanf(" %c", &res);
        
        //Going through the all 'res' options
        if (res == 'c') {

            printf("I guessed your number!\n");
            break;
        } 

        //Adjusting the range corresponding to the input
	else if (res == 'h') {
            high = guess - 1;  //If the user says the number is high it will change the upper bound
        } 
	else if (res == 'l') {
            low = guess + 1;   // If the user says the number is low it will change the low bound
	} 
	else {//Making sure that no invalid character is entered
            printf("Invalid input! Please enter 'h', 'l', or 'c'.\n");
        }
    }

    return 0;
}
