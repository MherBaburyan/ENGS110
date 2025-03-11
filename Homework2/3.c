#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    //Check if the string is NULL or empty, if it is, do nothing and return
    if (str == NULL || *str == '\0') {
        return;
    }

    //Declare two pointers, one for the start and one for the end of the string
    char *start = str;//Start points to the first character
    char *end = str + strlen(str) - 1; //End points to the last character

    //Loop to swap the characters from start to end until we meet in the middle
    while (start < end) {
        //Temporarily store the character at 'start'
        chartemp = *start;
        
        //Swap the characters
        *start = *end;
        *end = temp;

        // Move the start pointer one step forward and the end pointer one step backward
        start = start + 1;
        end = end - 1;
    }
}

int main() {
    //Declare a string with a size limit
    char str[100];

    //Ask the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //Use fgets to avoid buffer overflow

    //Remove the newline character if present (fgets includes the newline)
    str[strcspn(str, "\n")] = '\0';

    // Print the original string
    printf("Original string: %s\n", str);

    //Call the function to reverse the string in-place
    reverseString(str);

    //Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
