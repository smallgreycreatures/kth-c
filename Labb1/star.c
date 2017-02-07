#include <stdio.h>

int main()
{
	int n;
	int args = 1;
	while(args == 1) 
	{
		
		printf("Ange tal:\n");
		args = scanf("%d", &n);
		for (int i = 1; i <= n; i = i + 1)
			putchar('*');
		putchar('\n');
		
	}
	return 0;
}
