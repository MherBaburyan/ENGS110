#include <stdio.h>

int main(){

	//Defining the variabl	
	int grade;
	
	//Scanning the value			
	printf("Enter your grade: \n");
	scanf("%d", &grade);
	
	//This will constanlty ask for the grades, unless -1 is entered, which will stop the code
	while(grade!=-1){
	if(grade<60)
		printf("You have Failed the class Successfully");
	else if(grade<70)
		printf("Your grade is D");
	else if(grade<80)
		printf("Your grade is C");
	else if(grade<90)
		printf("Your grade is B");
	else if(grade<=100)
		printf("Your grade is A");
	
	//Asking for another input to keep the while loop going
	printf("\nEnter your grade: \n");
	scanf("%d", &grade);
}
	return 0;
	
}




