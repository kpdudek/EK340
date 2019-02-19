#include <stdio.h>
#include <math.h>

#define N 10
#define PI 3.14159

int main(){
	float radius[N] = {2.5,4.1,33.2,5.0,1.1,4.4,6.8,0.4,13.4,11.11};
	float area[N];
	int i;
	
	for(i=0; i<N; i++) {
		area[i] = PI * pow(radius[i],2);
	}

	printf("Radius:   Area:     \n");
	
	for(i=0; i<N; i++) {
		printf("%-8.2f  %-8.2f\n",radius[i],area[i]);

	}

	return 0;
}























