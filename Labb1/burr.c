#include <stdio.h>
#include <math.h>

int array_contains(int number, int arr[]);
void convert_int_to_array(int number, int *arr[]);
int main()
{
	int check = 1;
	int user_input_value;
	printf("Some text about burr\n");
	while (check) 
	{
		scanf("%d", &user_input_value);

		if (user_input_value > 0 && user_input_value < 10)
			check = 0;
		else
			printf("The value must be 0< and <9\n");

	}

	for (int i = 1; i < 100; i++)
	{
		int temp_val = user_input_value;

		int arr[(int)ceil(log10(i))];
		convert_int_to_array(i, &arr);

		if ((i%user_input_value)== 0)
			printf("Burr");			
		else if (array_contains(user_input_value, arr))
			printf("Burr");
		else
			printf("%d", i);

	}


}
void convert_int_to_array(int number, int *arr[])
{
	
	int array_index=0;
	while (number > 0) 
	{
		int digit = number % 10;
		arr[array_index] = digit;
		number /=10;
		array_index++;
	}
}

int array_contains(int number, int arr[])
{
	for (int j = 0; j < (sizeof(arr)/sizeof(int));j++)
	{
		if (arr[j] == number)
			return 1;

	}	
	return 0;	
}
