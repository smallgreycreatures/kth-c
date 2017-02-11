#include <stdio.h>
#include <stdlib.h>

struct BigInt {
	int number;
	int size;
	struct BigInt *tail;

};
const int MAX_SIZE = 500;
typedef struct BigInt BigInt;

void create_big_int(BigInt *big_int, char str_buf[])
{
	int size = 0;
	while(1)
	{
		if (str_buf[size] == NULL)
			break;
		size+=1;

	}
	BigInt *big_int_temp = big_int;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		big_int_temp->number = (str_buf[i]-'0');
		big_int_temp->size = size;
		BigInt *big_int_tail = malloc(sizeof(BigInt));
		big_int_temp->tail = big_int_tail;
		//printf("a%d\n", big_int_temp->number);
		
		if (str_buf[i] == NULL)
		{	
			big_int_tail = NULL;
			break;
		}
		else if (i == 0)
		{
			big_int_temp = big_int_tail;

		}
		else {
			big_int_temp = big_int_tail;
			big_int = big_int_temp;
		} 
	}

	//big_int = big_int_temp;
}

BigInt *add_big_ints(BigInt *big_int1, BigInt *big_int2)
{
	int carry = 0;
	int num1 = 0;
	int num2 = 0;
	int sum_int = 0;
	int null_flag = 0;
	BigInt *sum = malloc(sizeof(BigInt));
	BigInt *sum_tail = malloc(sizeof(BigInt));
	int size = 0;
	if (big_int1->size >=big_int2->size)
		size = big_int1->size +1;
	else
		size = big_int2->size +1;
	printf("size =%d\n", size);
	//printf("durr %d\n", big_int1->size);
	for (int i = 0; i < size; i++)
	{
		BigInt *sum_temp = malloc(sizeof(BigInt));

		if (null_flag == 1)
		{	
			num1 = 0;
			num2 = big_int2->number;
		}
		else if (null_flag == 2)
		{
			printf("Big int 2 == NULL\n");
			num2 =0;
			num1 = big_int1->number;
		}
		else
		{
			num1 = big_int1->number;
			num2 = big_int2->number;
		}

		sum_int = num1+num2+carry;
		printf("in %d\n",num2 );
		printf("sum int%d\n",sum_int );
		if(sum_int >= 10)
		{
			carry = 1;
			sum_temp->number = (sum_int%10);
		} else
		{
			carry = 0;
			sum_temp->number = sum_int;
			//printf("%d\n",sum_temp->number );
		}
		printf("sum_temp_num %d\n", sum_temp->number );
		sum_temp->size = size;
		printf("wtf %d, %d\n",i, carry);
		//printf("tail 1%d tail2%d\n", big_int1->tail->number, big_int2->tail->number);
		if (big_int1->tail == NULL && big_int2->tail == NULL)
		{
			if (carry == 0)
			{
				sum_temp->tail = sum_tail;
				sum = sum_temp;
				printf("st\n");
				break;
			} else if (carry == 1)
			{
				BigInt *sum_temp2 = malloc(sizeof(BigInt));
				sum_temp->tail = sum_tail;
				sum_temp2->number = 1;
				sum_temp2->size = size;
				sum_temp2->tail = sum_temp;
				sum = sum_temp2;
				break;
			}
		} else if (big_int1->tail == NULL)
		{
			big_int2 = big_int2->tail;
			null_flag = 1;

		} else if (big_int2->tail == NULL)
		{
			printf("doo\n");
			big_int1 = big_int1->tail;
			null_flag = 2;

		} else {
			big_int1 = big_int1->tail;
			big_int2 = big_int2->tail;
		}
		if (i == 0)
			sum_temp->tail == NULL;
		else	
			sum_temp->tail = sum_tail;
		sum_tail = sum_temp;

	}
	size++;
	printf("stuff %d\n", size);

	//To keep it ordered while adding size... 
	BigInt *temp = malloc(sizeof(BigInt));
	temp = sum;
	for(int i = 0; i < size; i++) {
		printf("%d",sum->number );

		if (sum->tail == NULL)
			break;
		sum = sum->tail;
		sum->size = size;

	}
	//free(big_int1);
	free(big_int2);
	sum = temp;
	return sum;
}

BigInt *reverse_BigInt(BigInt *big_int)
{
	BigInt *reversed_big_int = malloc(sizeof(BigInt));
	printf("str %d\n", big_int->size);
	int size = big_int->size;
	for (int i = 0; i < size; i++)
	{
		BigInt *temp_big_int = malloc(sizeof(BigInt));
		temp_big_int->number = big_int->number;
		temp_big_int->size = big_int->size;
		big_int = big_int->tail;
		if (i == 0)
			temp_big_int->tail = NULL;
		else
			temp_big_int->tail = reversed_big_int;
		
		reversed_big_int = temp_big_int;
		

		printf("%d\n", temp_big_int->number);
		//printf("%d\n", temp_big_int->size);
	}

	/*for(int i = 0; i < big_int->size; i++) {
		printf("rev :%d",reversed_big_int->number );
		reversed_big_int = reversed_big_int->tail;
	}*/
	return reversed_big_int;

}
void init_array_with_null(char array[])
{

	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i] = 0;
	}

}

int main()
{
	
	char str_buf[MAX_SIZE];
	init_array_with_null(str_buf);
	char str_buf2[MAX_SIZE];
	init_array_with_null(str_buf2);

	printf("Summera stora tal:\nAnge tal 1:");
	scanf("%s", &str_buf);
	printf("Tal två:");
	scanf("%s", &str_buf2);
	BigInt *big_int = malloc(sizeof(BigInt));
	create_big_int(big_int, str_buf);
	BigInt *big_int2 = malloc(sizeof(BigInt));
	create_big_int(big_int2, str_buf2);
	//printf("%d doo %d\n",big_int2->size, big_int2->number );
	big_int = reverse_BigInt(big_int);
	big_int2 = reverse_BigInt(big_int2);
	//printf("BS%d\n", big_int->size);
	BigInt *sum; 
	BigInt *sum1 = malloc(sizeof(BigInt));
	/*while (big_int->tail != NULL)
	{
		printf("%d\n",big_int->number );
		big_int = big_int->tail;
	}*/
	sum = add_big_ints(big_int, big_int2);
	//sum = reverse_BigInt(sum);
	//sum = add_big_ints(sum, big_int);
	printf("Back %d, %d\n", sum->size, sum->number);

}