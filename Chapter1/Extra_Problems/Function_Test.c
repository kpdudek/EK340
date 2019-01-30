#include <stdio.h>
#include <math.h>



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

int clear_buff() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { };
	return 0;
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















