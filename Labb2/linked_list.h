#include <stdio.h>
#include <stdlib.h>

typedef struct BigInt BigInt;

struct BigInt {
	int number;
	int size;
	struct BigInt *tail;

};

BigInt *add_big_ints(BigInt *big_int1, BigInt *big_int2);
BigInt *reverse_BigInt(BigInt *big_int);
void print_number(BigInt *number);
void print_sum_of(BigInt *big_int_input1, BigInt *big_int_input2, BigInt *sum);