#include <stdio.h>

int main(){
	//Defining variables
	int row, col;
	char chr;
	
	//Scanning the inputs
	printf("Enter number of rows: ");
	scanf("%d", &row);

	printf("Enter number of columns: ");
	scanf("%d", &col);

	getchar();//As a buffer error acccures when scanning different type of inputs, I used getchar() to get the Enter Key which the code understands as new line.

	printf("Enter the character: ");
	scanf("%c", &chr);
	
	//The nested loop which will print our rectangle
	for(int i=1; i<=row;i++){
		for(int j=1; j<=col; j++){
			if(i==1 || i==row){//If we are at the first or the last row, it should print a full row of character
				printf(" %c ",chr);
			}
			else{
				if(j==1 ||j==col){//If we are in the other rows, it should print the character only at the first and the last place of that row
					printf(" %c ", chr);
				}
				else{
					printf("   ");//Between the first and the last element of the row, it should print empry space
	}
		}

	}
		printf("\n");//Printing new line after every row
	}
	return 0;

}
