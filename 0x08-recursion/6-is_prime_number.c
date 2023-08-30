#include "main.h"

/**
 * prime_a - calculate if its prime
 * @a: input integer
 * @b: divisor
 * Return:(0).
 */
int prime_a(int a, int b)
{
	if (a <= 1 || (a != b && a % b == 0))
	{
		return (0);
	}
	else if (a == b)
	{
		return (1);
	}
	return (prime_a(a, b + 1));
}
/**
 * is_prime_number - calculate if a number is prime recursively
 * @n: number to evaluate
 *
 * Return: 1 or 0 if not
 */
int is_prime_number(int n)
{
	return (prime_a(n, 2));
}

