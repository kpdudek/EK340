#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
1) Write a program to initialize an array with a size of N with random integers, each in the range from 0 to MAXNUM.  It is to print these random integers, all on one line (using a field width of 3 for each).
   Then, the program is to loop to sum the elements in the array, printing each partial sum.  For example, the output window might look like this (the actual output will vary depending on the values of the
   constants and the random integers generated, but the format of the output window should be exactly like this):

    4   2   5   5   0   9   3

    So far the sum is 4
    So far the sum is 6
    So far the sum is 11
    So far the sum is 16
    So far the sum is 16
    So far the sum is 25
    So far the sum is 28
*/

int rand_num(int max)
{
	return rand()%(max+1);
}


void print_array(int my_array[], int size)
{
  printf("\n");
  printf("The random numbers are: ");
	for(int i=0;i<size;i++)
	{
		printf("%-3d",my_array[i]);
	}
	printf("\n");
}


void print_sums(int my_array[],int size)
{
	int sum = 0;
	for(int i=0;i<size;i++)
	{
		sum += my_array[i];
		printf("The sum is now: %-4d\n",sum);
	}
  printf("\n");
}


/*
	--- MAIN ---
*/

int main()
{
	srand(time(NULL));

	int len,max_val;

	printf("How long is the array? ");
	scanf("%d",&len);
	fflush(stdin);

	int nums[len];

	printf("Max value for random number? ");
	scanf("%d",&max_val);
	fflush(stdin);


	for(int i=0;i<len;i++)
	{
		nums[i] = rand_num(max_val);
	}

	print_array(nums,len);

	printf("\n");

	print_sums(nums,len);

	return 0;
}
