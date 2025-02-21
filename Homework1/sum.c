#include <stdio.h>

int main(){
	//Defining the variables
	int a, sum=0;

	//Scanning the value to the variable
	printf("Enter a number: ");
	scanf("%d", &a);
	
	//Checking i, which is the range of inputted number, whether it is multiple of 3 or 5
	for(int i=0; i<a; i++) {
		if(i%3==0 || i%5==0)//|| is or, meaning or multiple of 3 or multiple of 5 or both
		sum=sum+i;//Adds to the sum
}
	//Printing the sum
	printf("The sum of all multiples of 3 and 5 is %d\n", sum);

	return 0;

}
