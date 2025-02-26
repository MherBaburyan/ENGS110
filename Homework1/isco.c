#include <stdio.h>
 int main(){
	 //Declaring the variables
	 int b;
	 char chr;

	 //Scanning the values to the variables
	 printf("Enter the lenght of the base: ");
	 scanf("%d", &b);
	 getchar();
	 printf("Enter the symbol: ");
	 scanf("%c", &chr);

	int  height=(b+1)/2;
	 //Creating the triangle
	 for(int i=1; i<=height; i++){//How many rows will the triangle have
		 for(int j=i; j<height; j++){//This loop defines the number of spaces in a row. If i=1 j is also 1, the first row will have 3-1=2, 2 spaces, and so on
			 printf("   ");
		 }
		 for(int j=1; j<=(2*i-1);j++){//This loop defines the number of character printed. If j=1, (2*1-1)=1, and there will be 1 character on the first line
			 printf(" %c ", chr);
		 }
		 printf("\n");//New line after each row
	 }
	 return 0;
 }
