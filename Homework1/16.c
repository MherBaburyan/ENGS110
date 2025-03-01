#include <stdio.h>

int main() {
    //Declaring variables
    int count[10] = {0}; //Array to count occurrences of numbers 1-10
    int num;//Varibale will hold the value of the entered number

    printf("Enter numbers between 1 and 10 (enter -1 to stop):\n");
    
    //Scans all entered numbers. if -1 is entered the while loop will stop.
    //If a number between 1 and 10 is entered the code will add 1 to the index of the corresponding index
    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break; //Stop input when user enters -1
        } else if (num >= 1 && num <= 10) {
            count[num - 1] = count[num-1]+1;
	    //If num = 3, then count[3 - 1] = count[2] will add 1 to the count at the index of 2 therefore increasing the count for 3
        } else {
            printf("Please enter a number between 1 and 10.\n");
        }
    }

    printf("\nNumber of frequencies:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d - %d times\n", i + 1, count[i]);
    }

    return 0;
}
