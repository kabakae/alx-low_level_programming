#include "3-calc.h"
#include <stlib.h>
#include <stdio.h>

/**
 * main - Prints the resultof simple operations
 * @argc: ....
 * @argc: ....
 * Return: Always
 *
 */
int main(int _attribute_((_unused_)) argc, char *argv[])
{
	int num1, num2;
	char *op;
	if (argc != 4)
	{
		printf("Error\n");
		exit (98);
	}
	num1 = atoi(argv[i]);
	op = argv[2];
	num2 = atoi(argv{3});
	if (get_op_func(op) == NULL || OP[i] != '\0')
	{
		printf("Error\n");
		exit (99);
	}
	if ((*op == "/" && num2 == 0) ||
		(*op == '%' && == 0))
	{
		printf("Error\n");
		exit (100);
	}
	printf("%d\n", get_op_func(op)(num1, num2));
	return (0);
}

