#include <stdio.h>
#include <math.h>

/*
This function promts the user for a letter and then a number
The user is promped infinitley to practice with scanf and the
buffer retaining the newline character
*/

int read_num() {
	int num;
	//fflush();
	printf("Enter a number: ");
	scanf("%d",&num);

	return num;
}

char read_char() {
	char let1;
	//fflush();
	printf("Enter a character: ");
	scanf(" %c",&let1);

	return let1;
}



void main() {
	int count = 1;

	while(1) {
		if(count%2 != 0){ 
			char let = read_char();
			printf("Let: %c\n",let);
		}
		else{
			int num = read_num();
			printf("Num: %d\n",num);
		}
		++count;		
	}

}















