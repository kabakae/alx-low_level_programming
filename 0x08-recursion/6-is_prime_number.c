#include "main.h"

/**
 * is_prime_number - function that returns 1 if the input integer
   is a prime number, otherwise return 0.
 * @n: input integer
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}
/**
 * actual_prime - calculate if a number is prime recursively
 * @n: number to evaluate
 * @i: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int actual_sqrt_recursion(int n, int i)
{
	if (i + i > n)
		return (-1);
	if (i + i == n)
		return (i);
	return (actual_sqrt_recursion(n, i + 1));
}

