#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or
 * not a given unsigned integer is a palindrome.
 * @n: unsigned long n, to check palindrome or not.
 * Return: 0 :non palindrome | 1: palindrome.
 */


int is_palindrome(unsigned long n)
{
	unsigned long Quotion = 0, Rest, temp = n;

	while (n != 0)
	{
		Rest = n % 10;
		Quotion = Quotion * 10 + Rest;
		n = n / 10;
	}

	return ((Quotion == temp) ? (1) : (0));
}
