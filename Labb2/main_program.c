#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
const int MAX_SIZE = 500;

#define NULL_INT '\0' //defining a null value macro for ints :)
void init_array_with_null(char array[])
{
	//Arrays are not null filled in c. Null filling it makes life easier.
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i] = NULL_INT;
	}

}

void handle_user_input(char str_buf[], char prompt[])
{

	printf("%s\n",prompt);
	int i;
	while(1)
	{
		if (fgets(str_buf, MAX_SIZE, stdin)) {
			str_buf[strcspn(str_buf, "\n")] = NULL_INT; //Set the trailing newline to NULL!
 			break;
		} 
		else 
		{
			printf("Fel, försök igen\n");
		}
	}
}



void save_to_file(BigInt *sum)
{
	char str_buf[MAX_SIZE];
	handle_user_input(str_buf, "Ange filnamn: ");

	BigInt *temp_sum = malloc(sizeof(BigInt));
	temp_sum = sum; //temp var to enable printing of sum later...
	FILE *file;
	file = fopen(str_buf, "w");
	int size = sum->size;
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%d",temp_sum->number);
		if (temp_sum->tail != NULL)
			temp_sum = temp_sum->tail;
		
	}
	printf("Talet ");
	print_number(sum);
	printf(" är nu sparat i filen %s\n", str_buf);
	fclose(file);
	free(temp_sum);
}


int main()
{
	char str_buf1[MAX_SIZE];
	init_array_with_null(str_buf1);
	char str_buf2[MAX_SIZE];
	init_array_with_null(str_buf2);

	printf(" Hej och välkommen! \n Detta program summerar stora positiva heltal som kan bestå av max 500 siffror.\n");

	BigInt *big_int1 = malloc(sizeof(BigInt));
	BigInt *big_int2 = malloc(sizeof(BigInt));
	BigInt *big_int_rev1 = malloc(sizeof(BigInt));
	BigInt *big_int_rev2 = malloc(sizeof(BigInt));
	BigInt *sum = malloc(sizeof(BigInt));
	int count = 0;
	while (1)
	{
		if (count == 0)
		{
			handle_user_input(str_buf1, "Ange ett tal: ");
			//printf("str_buf1=%s\n", str_buf1 );

			//printf("Buffer %s\n",buffer );
			create_big_int(big_int1, str_buf1);
			big_int_rev1 = reverse_BigInt(big_int1);
			
			
		}

		handle_user_input(str_buf2, "Ange ett annat tal:");
		//printf("str_buf2=%s\n", str_buf2);
		
		if (str_buf2[0] == EOF)
		{	

			save_to_file(sum);
			printf("Tack och hej!\n");
		}
		create_big_int(big_int2, str_buf2);
		big_int_rev2 = reverse_BigInt(big_int2);
		sum = add_big_ints(big_int_rev1, big_int_rev2);
		print_sum_of(big_int1, big_int2, sum);
		count++;
		big_int1 = sum; //next iteration we work with sum
		
		big_int_rev1 = reverse_BigInt(sum);
	}

	//printf("Back %d, %d\n", sum->size, sum->number);
	return 0;
}