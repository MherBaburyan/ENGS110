#include <stdio.h>

int main(){
	
	//Declaring an array
	int arr[10];
	
	//Scanning the values to the array
	printf("Enter 10 numbers: ");
	for(int i=0; i<10; i++){
		scanf("%d", &arr[i]);
	}
	// Assumption to start the loop	
	int min=arr[0];
	int max=arr[0];
	
	//The loop which will find minimum and maximum
	for(int i=0; i<10; i++){
		if(arr[i]<min){
			min=arr[i];//If a number is smaller than the min(arr[0]), it will become the new minimum
		}
		else if(arr[i]>max){
			max=arr[i];//If a number is bigger than max(arr[0]), it will become the new maximum
		}
	}
	//Printing the maximum and the minimum
	printf("Max is %d, Min is %d\n", max, min);
	return 0;
}
