#include <stdio.h>
#include <stdlib.h>

//Function to find and report the locations of { and } in a given file
void find_parentheses(const char *filename) {
    //Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: The file '%s' was not found.\n", filename);
        return;
    }
    
    char ch; //Declaring variable to store each character read from the file
    int row = 1, col = 0; //Tracking row and column positions
    
    //Printing results
    printf("\nLocations of '{' and '}' in the file:\n");
    printf("Character | Row | Column\n");
    printf("------------------------\n");
    
    //Read the file
    while ((ch = fgetc(file)) != EOF) {
        col=col+1; //Increment column number
        
        //If a newline is encountered, move to the next row and reset column
        if (ch == '\n') {
            row=row+1;
            col = 0;
        }
        
        //Checking if the character is { or } and print its location
        if (ch == '{' || ch == '}') {
            printf("    %c     | %3d | %3d\n", ch, row, col);
        }
    }
    
    //Closing the file
    fclose(file);
}

int main() {
    //Declaring the variable with  the filename, as we want to read the same file (this one) we give the name of the file
    char filename[] = "1.c";
    
    //Calling the function
    find_parentheses(filename);
    
    return 0;
}
