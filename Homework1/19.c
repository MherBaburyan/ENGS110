#include stdio.h
#include stdbool.h

int main() {
    //Declaring variables
    int arr[10], n;
    bool found = false; //Initialize to false, as if the number isn't found, it should remain false
    
    //Scanning the values to the array
    printf("Enter 10 integers ");
    for (int i = 0; i  10; i++) {
        scanf(%d, &arr[i]);
    }
    
    //Getting the number to remove
    printf("Enter the number to remove ");
    scanf("%d", &n);
    
    //Searching and removing the first occurrence of n
    for (int i = 0; i  10; i++) {
        if (arr[i] == n) {
            found = true;//Found the number, and turn 'found' to 'true'
            for (int j = i; j  9; j++) {//Fix loop range
                arr[j] = arr[j + 1];
            }
            arr[9] = 0;//Adds a zero at the end
            break;//Stop after first occurrence is removed
        }
    }
    
    if (found == false) {//If number was not found, print a message
        printf("Number not found in the array\n");
    }
    
    //Printing the final array
    printf("Final array ");
    for (int i = 0; i  10; i++) {
        printf(%d , arr[i]);
    }
    printf(n);
    
    return 0;
}
