#include <stdio.h>
#include <math.h>

#define rows 3
#define cols 3

int main(){
	
	int i,j;
	int array[rows][cols] = {{1,2,3},{4,5,6},{7,8,9}};

	printf("Column 1: Column 2: Column 3:\n");

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%-10d",array[i][j]);
		}
		
		printf("\n");
	}

	return 0;
}























