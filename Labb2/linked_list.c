#include <stdio.h>
#include <stdlib.h>

struct BigInt {
	int number;
	struct BigInt *tail, *nose;

};
const int MAX_SIZE = 500;
typedef struct BigInt BigInt;

void create_big_int(BigInt *big_int, char str_buf[])
{

	BigInt *big_int_temp = big_int;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		big_int_temp->number = (str_buf[i]-'0');
		BigInt *big_int_tail = malloc(sizeof(BigInt));
		big_int_temp->tail = big_int_tail;
		//printf("a%d\n", big_int_temp->number);
		
		if (i == 4)
		{	
			big_int_tail = NULL;
			break;
		}
		else if (i == 0)
		{
			big_int_temp->nose = NULL;
			big_int_temp = big_int_tail;
		}
		else {
			big_int_temp = big_int_tail;
			big_int_temp->nose = big_int;
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
	BigInt *sum = malloc(sizeof(BigInt));
	BigInt *sum_tail = malloc(sizeof(BigInt));
	for (int i = 0; i < 4; i++)
	{
		BigInt *sum_temp = malloc(sizeof(BigInt));
		num1 = big_int1->number;
		num2 = big_int2->number;

		sum_int = num1+num2+carry;
		printf("in %d\n",sum_int );
		if(sum_int >= 10)
		{
			carry = 1;
			sum_temp->number = (sum_int%10);
		} else
		{
			carry = 0;
			sum_temp->number = sum_int;
			printf("%d\n",sum_temp->number );
		}
		big_int1 = big_int1->tail;
		big_int2 = big_int2->tail;
		
		if (i == 0)
		{
			sum_temp->tail = NULL;
		} else
		{
			sum_temp->tail = sum_tail;
		}

		sum_tail = sum_temp;
		if (i == 3)
		{
			BigInt *sum_temp = malloc(sizeof(BigInt));
			sum_temp->number = carry;
			sum_temp->tail = sum_tail;
			sum = sum_temp;
			free(sum_temp);
		}	
	}
	for(int i = 0; i < 5; i++) {
		printf("%d",sum->number );
		sum = sum->tail;
	}
	free(big_int1);
	free(big_int2);

	return sum;
}

BigInt *reverse_BigInt(BigInt *big_int)
{
	BigInt *reversed_big_int = malloc(sizeof(BigInt));

	for (int i = 0; i < 4; i++)
	{
		BigInt *temp_big_int = malloc(sizeof(BigInt));
		temp_big_int->number = big_int->number;
		big_int = big_int->tail;
		temp_big_int->tail = reversed_big_int;
		reversed_big_int = temp_big_int;
		//printf("%d\n", temp_big_int->number);
	}
/*	for(int i = 0; i < 4; i++) {
		printf("%d",reversed_big_int->number );
		reversed_big_int = reversed_big_int->tail;
	}*/
	return reversed_big_int;

}

int main()
{
	
	char str_buf[MAX_SIZE];
	char str_buf2[MAX_SIZE];
	printf("Summera stora tal:\nAnge tal 1:");
	scanf("%s", str_buf);
	printf("Tal två:");
	scanf("%s", str_buf2);
	BigInt *big_int = malloc(sizeof(BigInt));
	create_big_int(big_int, str_buf);
	BigInt *big_int2 = malloc(sizeof(BigInt));
	create_big_int(big_int2, str_buf2);
	big_int = reverse_BigInt(big_int);
	big_int2 = reverse_BigInt(big_int2);
	BigInt *sum; 
	BigInt *sum1 = malloc(sizeof(BigInt));
	sum = add_big_ints(big_int, big_int2);

	/*while (sum->tail != NULL)
	{
		printf("%d\n",sum->number );
		big_int = sum->tail;
	}*/
}