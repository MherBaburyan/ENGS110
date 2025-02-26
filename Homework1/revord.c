#include <stdio.h>

int main(){
	//Declaring a variable which will be the size of the array	
	int n;
	
	//Getting the size
	printf("Enter the size: ");
	scanf("%d", &n);
	
	//Declaring an array of size n
	int arr[n];
	
	//Loop will get the values for the array
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//This loop will print the array in reverse order
	printf("Reveresed order\n");
	for(int i=n-1; i>=0; i--){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

