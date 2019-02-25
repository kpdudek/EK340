#include <stdio.h>
#include <math.h>

#define N 10
#define PI 3.14159

int main()
{
	// Define the radius value array, and create an empty areas array
	float radius[N] = {2.5,4.1,33.2,5.0,1.1,4.4,6.8,0.4,13.4,11.11};
	float area[N];
	int i;
	
	// Loop through array Radius, calculate the area, and then save the area value in
	// the area array.
	for(i=0; i<N; i++)
	{
		area[i] = PI * pow(radius[i],2);
	}
	

	// Print the table header
	printf("Radius:   Area:     \n");
	
	// Loop through the area array and print values in table format	
	for(i=0; i<N; i++)
	{
		printf("%-8.2f  %-8.2f\n",radius[i],area[i]);

	}


	return 0;
}























