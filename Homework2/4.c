#include <stdio.h>
#include <string.h>

void compressString(char *str) {
    //First, check if the string is NULL or empty
    if (str == NULL || *str == '\0') {
        return;
    }

    int length = strlen(str); //Find the length of the string
    int count = 1;  //This will count the occurrences of each character

    //Start a new position for the compressed string
    int newIndex = 0;

    //Loop through the string starting from the second character
    for (int i = 1; i <= length; i++) {
        //Check if the current character is the same as the previous one
        if (str[i] == str[i - 1]) {
            count = count + 1;  // Increment the count if characters match
        } else {
            //Write the current character to the new position
            str[newIndex] = str[i - 1];

            //Write the count as a string (if greater than 1)
            if (count > 1) {
                newIndex = newIndex + 1; //Move to the next position
                str[newIndex] = count + '0'; //Convert count to char and store it
            }
            newIndex = newIndex + 1;  //Move to the next position for the next character
            count = 1;  //Reset the count for the new character
        }
    }

    //Null terminate the string to ensure it remains a valid string
    str[newIndex] = '\0';
}

int main() {
    //Declare a string for testing
    char str[100];

    //Ask the user to input a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //Use fgets to avoid buffer overflow

    //Remove the newline character if it exists
    str[strcspn(str, "\n")] = '\0';

    //Print the original string
    printf("Original string: %s\n", str);

    //Call the function to compress the string
    compressString(str);

    //Print the compressed string
    printf("Compressed string: %s\n", str);

    return 0;
}

