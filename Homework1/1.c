#include <stdio.h>

int main() {
	//Defining variables
	double num1, num2, res;
	char oper;
	
	//Scanning the vakues to the variables
	printf("Enter an expression\n");
	scanf("%lf %c %lf", &num1, &oper, &num2);
	
	//Switch case for the calculator based on the 'oper'(operation) variable
	switch(oper){
		case '+':
			res=num1+num2;
			printf("%.2f + %.2f = %.2f", num1, num2, res);
		      break;	

		case '-':
			res=num1-num2;
			printf("%.2f - %.2f = %.2f", num1, num2, res);
			break;

		case '*':
         		res=num1*num2;
         		printf("%.2f * %.2f = %.2f", num1, num2, res);
	 	      break;	
                                                                  
         	case '/':
         		res=num1/num2;
         		printf("%.2f / %.2f = %.2f", num1, num2, res);
		}
	printf("\n");
	return 0;
}



