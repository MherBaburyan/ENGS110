#include <stdio.h>

int main(){
	//Declaring variables
	int num, digit;
	int z=0;

	//Scanning values to the variable
	printf("Enter a number: ");
	scanf("%d", &num);
	
	
	int n1=num, n2=num;//Storing the number in another variables

	//Deviding the number by 2 and counting the number of bits needed
	while(n1!=0){                   
			n1=n1/2;
			z++;
	}

	int arr[z], rev[z];//Declaring an array to store the digits and also an array for the reversed order
	while(n2!=0){//Deviding the number by 2, storing the remainder in the array
			for(int i=0; i<z;i++){
			digit=n2%2;
			arr[i]=digit;
			n2=n2/2;  
			}	
              
	}	
	//Reversing and storing in another array
	for(int i=0; i<z; i++){
		rev[i]=arr[z-1-i];
	}

	printf("The binary represetation of %d is ", num);
	if(num==0){//If num is 0,it will print 0
		printf("0");
	}
	else if(num>0){//If number is bigger than 0, it will print the rev[] which holds the binary form
		printf("0");
		for(int i=0; i<z; i++){
			printf("%d", rev[i]);
		}
	}
	else if(num<0){// If the number is negative, we must compute 2s compliment
		printf("1");
		for(int i=0; i<z; i++){//We toggle the digits, if 0 it becomes 1; if 1 it becomes 0
			rev[i] = (rev[i]+1)%2;
		}
		//Now we should add 1 
		int c=1;
		for(int i=z-1; i>=0; i--){//We start adding 1 from the end
			if(rev[i]==0){
				rev[i]=1;
				c=0;
				break;//If the digit is 0, we add 1 and break
			}
			else{
				rev[i]=0;
			}
		}
		for(int i=0; i<z; i++){
			printf("%d", rev[i]);
}

}
	printf("\n");
	return 0;
}

		

		
                                                                                                   
