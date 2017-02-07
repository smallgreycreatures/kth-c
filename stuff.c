#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 1000;
	int s1 = 0;
	int s2 = 0;
	char *c;
	char str_buf[size];
	char str_buf2[size];

	scanf("%s", str_buf);
	

	scanf("%s", str_buf2);

	for (int i = 0; i < size; i++)
	{
		if (str_buf[i] == 'h'){
			s1 = i;
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (str_buf2[i] == 'h'){
			printf("go\n");
			return 0;
		} else if (i >= s1) {
			printf("no\n");	
			return 0;	
		}
	}	


	
	return 0;
}