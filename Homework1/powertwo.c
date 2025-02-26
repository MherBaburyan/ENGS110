#include <stdio.h>

int powertwo(int num){
	
	if(num<=0){//As negatives numbers and 0 is not power of 2, it will return 0(Not power of 2)
		return 0;
	}
	while(num>1){//If the number is bigger than 1, we start the while loop
		if(num%2!=0){//If at any point the remainer is not 0, it will return 0(Not power of 2)
			return 0;
		}
		num=num/2;//If the remainder is not 0, we continue deviding it by 2
	}
	return(num==1);//This will return 1(power of 2) if the num is 1 after the while loop
}
int main(){

	//Declaring variables
	int num;

	//Scanning the vlaue to the variable
	printf("Enter the number: ");
	scanf("%d", &num);

	//If powertrue function returns true, we print that the number is power of two
	if(powertwo(num)){
		printf("It is a power of 2\n");
	}
	else{
		printf("Number is not power of 2\n");
	}
	return 0;
}
