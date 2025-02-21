#include <stdio.h>

int main(){
	//Defining variables
	int num, digit, revnum=0;
	
	//Scanning the value to the variable
	printf("Enter a number: ");
	scanf("%d", &num);
	
	//Chekcs if the number is >=1
	while(num>=1){
		digit=num%10;//Takes the remainder
		revnum=revnum*10+digit;
	//Takes the remainder, adds to revnum which is 0, gets a new value for the revnum=remainder. Then it multiples it by 10 and add the other remainder and so on
		num=num/10;//Devides the number by 10
	}
	//Printing the reversed number
	printf("Reversed number is %d\n", revnum);

	return 0;

}
