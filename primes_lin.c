#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//const int MAX_INT = 1000000;
int zero_arr[1000000];

int main() 
{
	int n;

 	scanf("%d", &n);

	int lp[n+1];
	memcpy(lp, zero_arr, (n+1)*sizeof(int));
	//for (int k = 0; k < n; k++)
	//	printf("%d\n", lp[k]);
	
	int counter = 0;
	int pr[n];
	for (int i=2; i<n; ++i) {
    	if (lp[i] == 0) {
        	lp[i] = i;
        	pr[counter] = i;
        	counter++;
        	printf("%d ",i );
    	}

		
   		for (int j=0; j<counter && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
        	lp[i * pr[j]] = pr[j];
	}  
	
}