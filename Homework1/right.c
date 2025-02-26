#include <stdio.h>

int main(){
	//Declaring variables
	int a;
	char chr;
	//Scanning the values to the variables
	printf("Enter the height: ");
	scanf("%d", &a);
	getchar();//I added this so Enter Key(new line) wont be captured as chr
	printf("Enter the character: ");
	scanf("%c", &chr);
	//Printing the character from the left
	for(int i=1; i<=a;i++){
		for(int j=1; j<=i;j++){
			printf(" %c ", chr);
		}
		printf("\n");
	}
	printf("\n");//New line between two triangles
	//Printing the character from the right
	for(int i=1; i<=a; i++){
		for(int j=i+1; j<=a;j++){
			printf("   ");//Printing empty spaces where the character should not be printed
	}
		for(int j=1;j<=i;j++){
			printf(" %c ",chr);

	}
	printf("\n");
	}
			
	return 0;

}
