#include <stdio.h>

int main()
{
	//Defining variables
	int number,number1, revnum=0, digit=0;

	//Scanning the value to the variable
	printf("Enter a number: ");
	scanf("%d", &number);
	
	//Storing the input in another variable to use the original later
	number1=number;

	//Reversing the number
	while(number1>0){
		digit=number1%10;
		revnum=revnum*10+digit;
		number1=number1/10;
	}
	printf("Reversed number is %d\n", revnum);
	
	//This checks if the reversed number is the same as the input
	if(revnum==number)
		printf("Number is a Palindrome\n");
	else
		printf("Number is not a Palindrome\n");

	return 0;

}
