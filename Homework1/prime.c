#include <stdio.h>
#include <stdbool.h>

//This function gets a number from the main function and checks if it is prime or not
bool prime(int n){
	bool pr=true;
	for(int i=2;i<n;i++){
		if (n%i==0){
			pr=false;
			break;//If this loop finds that there is such i for which the number/i devision remainder is 0, changes the value of bool pr to false
		}
	}
	return pr;//Returning the value of pr, which is either false (in case that it is not prime), or true (in case that it is prime)
}
int main(){
	//Defining variables
	int num;
	bool isprime;
	
	//Scanning the input to the variable
	printf("Enter a number: ");
	scanf("%d", &num);

	//As prime numbers start from 2, in case of 0 and 1 it will not start the loop
	if(num<2){
		printf("Not Prime");
	}
	else {//Sends values of i in the range of n to check if they are prime or not
		printf("Prime numbers are: ");
		for(int i=2; i<=num;i++){
			isprime=prime(i);
			if(isprime==true){
				printf("%d ", i);//Prints the prime numbers in the range of n
			}
		}
	}
	printf("\n");
	return 0;
}

