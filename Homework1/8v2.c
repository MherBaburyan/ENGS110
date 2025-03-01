#include <stdio.h>
#include <math.h>

int main(){

	int num1,num2,i=0,conc=0,n2;

	printf("Enter a number to which you want to concatinate to: ");
	scanf("%d", &num1);
	printf("Enter a number which will be concatinated: ");
	scanf("%d", &num2);

	n2=num2;

	while(n2>=1){
		i++;
		n2=n2/10;
	}

	conc=num1*pow(10,i)+num2;
	printf("%d\n", conc);

	return 0;
}
