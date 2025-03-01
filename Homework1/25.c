#include <stdio.h>

int main() {
    //Declaring variables
    int n, k, m;
    
    // Get the number of elements and the original array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int og[n], arrFront[n + 1], arrEnd[n + 1], arrPos[n + 1];
    //One to store the original, one for the addition from the end, one from the front, and one at user speicified position. The new arrays(not the original one) must have +1 to size to have space for the new element to be added
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &og[i]);
    }
    
    //Get the number to insert
    printf("Enter the number to insert: ");
    scanf("%d", &k);

    //Place the new element at index 0
    arrFront[0] = k;
    
    //Copy the original elements after the inserted element
    for (int i = 0; i < n; i++) {
        arrFront[i + 1] = og[i];
    }
    //Copy all the original elements first
    for (int i = 0; i < n; i++) {
        arrEnd[i] = og[i];
    }
    //Place the new element at the end
    arrEnd[n] = k;
    
    printf("Enter the position to insert: ");
    scanf("%d", &m);
    
    //Check if the position is valid
    if (m < 1 || m > n + 1) {//As we are working with postitions and not indexes, it cannot be smaller than 1 and bigger than n+1(increased size to have space for the new element)
        printf("Invalid position!\n");
        return 1;
    }
    
    //Copy elements before the insertion point
    for (int i = 0; i < m - 1; i++) {
        arrPos[i] = og[i];
    }
    //Insert the new element at position m-1 (0-indexed)
    arrPos[m - 1] = k;
    //Copy the remaining elements
    for (int i = m - 1; i < n; i++) {
        arrPos[i + 1] = og[i];
    }
    //Printing arrays
    printf("Array after inserting at the beginning: ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arrFront[i]);
    }
    printf("\n");
    
    printf("Array after inserting at the end: ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arrEnd[i]);
    }
    printf("\n");
    
    printf("Array after inserting at position %d: ", m);
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arrPos[i]);
    }
    printf("\n");
    
    return 0;
}
