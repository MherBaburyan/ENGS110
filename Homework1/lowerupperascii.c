#include <stdio.h>
#include <string.h>
//In the other code, I used the commands to turn the strings to uppercase
//Here I tried it with ASCII table
int main() {
    //Declaring variables
    char input[100];
    int ch;
    //Getting the string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;//Remove newline character if present
    
    printf("Choose an option:\n1-Convert to Uppercase\n2-Convert to Lowercase\n");
    scanf("%d", &ch);
    
    //Depending on the choice, it will either turn the string to uppercase or lowercase
    switch (ch) {
        case 1:
            for (int i = 0; input[i] != '\0'; i++) {//Stopping when we come to \0 which indicates the end of data
                if (input[i] >= 'a' && input[i] <= 'z') {//Checking if all are lowercase
                    input[i] = input[i] - ('a' - 'A');//If lowercase, I subtract the value of (a - A) which is (97 -65) = 32, turning the string to lowercase
                }
            }
            printf("Uppercase: %s\n", input);
            break;
        
        case 2:
            for (int i = 0; input[i] != '\0'; i++) {//Stopping when we come to \0 which indicates the end of data
                if (input[i] >= 'A' && input[i] <= 'Z') {//Checking if the string is uppercase
                    input[i] = input[i] + ('a' - 'A');//If uppercase, I add 32 to the value, turning it to lowercase
                }
            }
            printf("Lowercase: %s\n", input);
            break;
        
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}