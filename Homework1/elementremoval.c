#include <stdio.h>

int main() {
    //Declaring variables
    int n, m;
    
    //Getting the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    //Getting user input for array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    //Getting the position to delete
    printf("Enter the position to delete: ");
    scanf("%d", &m);
    
    //Checking if m is valid, as we want to work with positions and not indexes m must be from 1 to n
    if (m < 1 || m > n) {
        printf("Invalid position!\n");
        return 1;
    }
    
    //Shifting elements to remove m-th element
    for (int i = m - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
        //Each element at index i is replaced by the next element arr[i + 1].
        //This shifts all elements from index m to the left by one position.
    }
    
    //Printing the final array
    printf("Final array: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
