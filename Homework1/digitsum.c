#include <stdio.h>

int main() {
	//Defining variables	
	int num, digit, sum=0;
	
	//Scanning the value to the variable
	printf("Enter a number: ");
	scanf("%d", &num);
	
	//This loop devides the 'num' by 10 and takes the remainder and adds it to the sum
	while(num>=1){
		digit=num%10;
		sum=sum+digit;
		num=num/10;
	}
	
	//Printing the sum value
	printf("Sum of digits is %d\n", sum);
	 return 0;

}

