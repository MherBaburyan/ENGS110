#include <stdio.h>
#include <stdbool.h>

int main() {
    //Declaring variable for the size of the array
    int n; 
    //Declaring bool variables for sorting, by default lets set it to true
    bool ascending = true, descending = true;

    //Getting the value of the size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    //scanning the values to the array
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Checking for sorting order
    for(int i = 1; i < n; i++) {
        //Checking for the ascending order
        if(arr[i] < arr[i - 1]) {//If we find that the previous value of the array is bigger than the current array value, that means it is not ascending
            ascending = false;//Changing to false
        }
        
        if(arr[i] > arr[i - 1]) {//If we find that the the current array value is bigger than the previous value, that means it is not descending
            descending = false;//Changing to false
        }
    }

    //Printing the result
    if(ascending || descending) {//If any are true, meaning thast it is either ascendning or descending, it prints 'Yes', meaning it is sorted in any way
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
