#include <stdio.h>
/* References I used
Lecture - ://elearning.aua.am/pluginfile.php/86087/mod_resource/content/1/fsm.c
Online - https://www.codeproject.com/Articles/1275479/State-Machine-Design-in-C
Youtube - https://youtu.be/2OiWs-h_M3A?si=G3XqgrIVS5jK-Pkl
*/
//Declaring the FSM states
enum State {IDLE, SCANNED, GRANTED, DENIED};

int main() {
    //Starting from IDLE state
    enum State current = IDLE;
    
    //Defining variables that will hold the input and whether to continue or not
    char input;
    char cont = 'y';

    printf("Welcome to Best Subway Entry Simulator by Mher Baburyan\n");
    printf("Mher's Subawy Entry System Simulation\n");
    
    //While the user input is either y or Y it will continue asking for inputs from the user
    while (cont == 'y' || cont == 'Y') {
        printf("\nEnter a card type (S = Student, G = Guest, I = Invalid): ");
        scanf(" %c", &input);  // Skip whitespace before reading char

        //Validate the input, anc checking if it is a vvalid input
        if (input != 'S' && input != 'G' && input != 'I') {
            printf("Invalid input. Please enter S, G, or I.\n");
            continue;
        }

        printf("\nCard scanned: %c\n", input);

        //Transiting to SCANNED state and granting access based on the input
        current = SCANNED;

        switch (current) {
            case SCANNED:
                printf("State: SCANNED\n");

                if (input == 'S' || input == 'G') {
                    current = GRANTED;
                } else if (input == 'I') {
                    current = DENIED;
                }
                break;
        }

        //Will print Granted or Denied based on the input
        switch (current) {
            case GRANTED:
                printf("Access Granted. Welcome aboard!\n");
                break;
            case DENIED:
                printf("Access Denied. Please try again.\n");
                break;
        }

        // Return to idle
        current = IDLE;

        // Ask if user wants to continue
        printf("\nDo you want to scan another card? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("\nThanks for using Mher's Subway Entry System. See you and have a nice ride!\n");
    return 0;
}
