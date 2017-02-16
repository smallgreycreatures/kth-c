#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <string.h>
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

	printf("%s",prompt);
	int i;
	while(1)
	{
		if (fgets(str_buf, MAX_SIZE, stdin)) {
			str_buf[strcspn(str_buf, "\n")] = NULL_INT; //Set the trailing newline to NULL!
 			break;
		} 
		else 
		{
			str_buf[0] = EOF;
			fseek(stdin,0,SEEK_END);
			break;
			
		}
	}
}



void save_to_file(BigInt *sum)
{
	char str_buf[MAX_SIZE];
	handle_user_input(str_buf, "\nAnge filnamn: ");

	BigInt *temp_sum;
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
}


int main()
{
	char str_buf1[MAX_SIZE];
	init_array_with_null(str_buf1);
	char str_buf2[MAX_SIZE];
	init_array_with_null(str_buf2);

	printf(" Hej och välkommen! \n Detta program summerar stora positiva heltal som kan bestå av max 500 siffror.\n");

	BigInt *big_int1 = malloc(sizeof(BigInt));
	BigInt *big_int2;
	BigInt *big_int_rev1;
	BigInt *big_int_rev2;
	BigInt *sum;

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
		sum = big_int1;
		handle_user_input(str_buf2, "Ange ett annat tal (eller avsluta genom crtl-d): ");
		//printf("str_buf2=%s\n", str_buf2);
		
		if (str_buf2[0] == EOF)
		{	

			save_to_file(sum);
			free_BigInt(sum);
			free_BigInt(big_int_rev1);
			printf("Tack och hej!\n");
			break;
		}
		big_int2 = malloc(sizeof(BigInt));
		create_big_int(big_int2, str_buf2);
		big_int_rev2 = reverse_BigInt(big_int2);
		sum = add_big_ints(big_int_rev1, big_int_rev2);
		print_sum_of(big_int1, big_int2, sum);
		count++;
		//printf("Big int1 before = %d %d\n", big_int1->number, big_int1->tail->number);
		free_BigInt(big_int1);
		free_BigInt(big_int2);
		free_BigInt(big_int_rev1);
		free_BigInt(big_int_rev2);
		big_int1 = sum; //next iteration we work with sum

		//printf("Big int1 after = %d %d\n", big_int1->number, big_int1->tail->number);
		big_int_rev1 = reverse_BigInt(sum);

	}

	//printf("Back %d, %d\n", sum->size, sum->number);
	return 0;
}