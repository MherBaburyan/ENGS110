#include <stdio.h>
#include <ctype.h>

int main() {
    //Declaring the variables
    char str[100];//Buffer to store the input string
    int ch;

    //Getting the input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);//Scanning the input string, including spaces

    //Lower or Upper
    printf("Choose an option:\n1-Convert to Uppercase\n2-Convert to Lowercase\n");
    scanf("%d", &ch);

    //Switch statement for turning to upper or lower case
    switch (ch) {
        case 1:
            //Converting to uppercase
            for (int i = 0; str[i] != '\0'; i++) {//str[i] != '\0' is to stop when we come to the end of the string. When we come to the last member, the code adds \0 to indicate the end of the arr.
                str[i] = toupper(str[i]);
            }
            printf("Uppercase: %s\n", str);
            break;
        case 2:
            // Converting to lowercase
            for (int i = 0; str[i] != '\0'; i++) {//str[i] != '\0' is to stop when we come to the end of the string. When we come to the last member, the code adds \0 to indicate the end of the arr.
                str[i] = tolower(str[i]);
            }
            printf("Lowercase: %s\n", str);
            break;
        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
    }

    return 0;
}
