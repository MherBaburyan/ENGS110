#include <stdio.h>

int main(){
	
	//Declaring variables
	int num1, num2, conc=0;

	//Scanning values to the variables
	printf("Enter the number to which you want to concatinate: ");
	scanf("%d", &num1);
	printf("Enter the number, which will be concatinated: ");
	scanf("%d", &num2);

	int temp = num2;
	
	//Counting number of digits of num2 and multiplying num1 by 10 for each digit of num2
	while(temp>=1){
		num1=num1*10;
		temp=temp/10;
	}

	//Summing to get the concatinated value
	conc=num1+num2;
	printf("Concatinated number: %d\n", conc);

	return 0;
}
