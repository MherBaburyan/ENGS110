#include <stdio.h>

int main(){

	//Declaring the variable which will be the size and the sum
	int n, sum=0;
	
	//Scanning the value to the variable
	printf("Enter the size: ");
	scanf("%d", &n);
	
	//Declaring an array of size n
	int arr[n];
	
	//Getting the values
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	//Summing
	for(int i=0; i<n; i++){
		sum=sum+arr[i];
	}
	printf("The sum of inputed numbers is %d\n", sum);
	return 0;
}

