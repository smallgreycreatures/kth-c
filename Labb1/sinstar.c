#include <stdio.h>
#include <math.h>

int main()
{
	double maxVal = 6.3;
	double step = 0.3;
	int numberOfIterations = maxVal/step;
	int x = 0;
	int left_spacer = 30;

	for (int i = 0; i < numberOfIterations; i++) 
	{
		x = step*i;

		double sin_val = sin(x);
		//printf("%f\n",sin_val);
		for (int j = 0; j <(left_spacer+(15*sin_val)); j++)
			printf("*");
	printf("\n");
	}
	return 0;
}