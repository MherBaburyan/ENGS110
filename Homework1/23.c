#include <stdio.h>

int main() {
    //Declaring variables
    int n, temp, sort;
    
    //Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    //Scanning the values to the array
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    //Asking the user for the desired sorting order
    printf("Choose sorting order:\n1 - Ascending\n2 - Descending\n");
    scanf("%d", &sort);
    
    //Using a switch to determine which sorting order to apply
    switch(sort) {
        case 1:
            //Bubble Sorting for ascending
            for(int i = 0; i < n - 1; i++){
                for(int j = 0; j < n - i - 1; j++){
                    if(arr[j] > arr[j + 1]){//Takes to values arr[j] and arr[j+1], and checkes if the arr[j+1] is bigger than arr[j]
                        temp = arr[j];//If arr[j+1] isbigger than arr[j], it stores the value of arr[j] in a temp variable
                        arr[j] = arr[j + 1];//Stores the value of arr[j+1] in the arr[j]
                        arr[j + 1] = temp;//Stores the value of temp (which is the original arr[j]) in the arr[j+1]
                        //This simple algorithm changes the values off arr[j] and arr[j+1] if the arr[j+1] is bigger 
			//Therefore sorting them in ascending order, and does this for all pairs
                    }
                }
            }
            printf("\nSorted numbers in ascending order: ");
            break;
            
        case 2:
            // Bubble Sort for descending
            for(int i = 0; i < n - 1; i++){
                for(int j = 0; j < n - i - 1; j++){
                    if(arr[j] < arr[j + 1]){
		//Same thing but this time we check if the arr[j] is bigger than arr[j+1]
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("\nSorted numbers in descending order: ");
            break;
    }
    
    //Printing the sorted array
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
