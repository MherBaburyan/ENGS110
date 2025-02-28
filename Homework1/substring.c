#include <stdio.h>
#include <string.h>

int main() {
    //Declaring arrays which will hold our strings
    char str1[100], str2[100];
    
    //Getting the strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';//Removing the '\0'

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';//Removing the '\0'
    
    //Checking if str2 is a substring of str1 or the other way around. For this I used 'strstr' which searches for the first occurrence of a substring in a string. If it finds the substring, it returns a pointer to the first occurrence; otherwise, it returns NULL.
    if (strstr(str1, str2) != NULL) {  
        //If strstr returns NULL, that means there are no similarities
        //If it is not NULL, therefore str2 is a substring
        printf("\"%s\" is a substring of \"%s\".\n", str2, str1);
         } 
    else if (strstr(str2, str1) != NULL) {
        //If strstr returns NULL, that means there are no similarities
        //If it is not NULL, therefore str1 is a substring
        printf("\"%s\" is a substring of \"%s\".\n", str1, str2);
    } 
    else {
        printf("Neither string is a substring of the other.\n");
    }

    return 0;
}
