#include "sort.h"


/**
 * len - checks max element
 * @size: array size
 * @array: first element of array (pointer)
 * Return: max number of digits
 */
int len(int *array, size_t size)
{
	int i, j, n = 0;

	for (i = 0; i < (int)size; ++i)
		if (array[i] > n)
			n = array[i];
	for (j = 0; n >= 1; ++j)
		n = n / 10;

	return (j);
}
/**
 * radix_sort - sorts an array using Radix sort algorithm
 * @size: size of array
 * @array: pointer integer, first element of array to sort
 */
void radix_sort(int *array, size_t size)
{
	int Forward[100][100], Back[100];
	int i, j, k, r, c, max;
	int div = 1;

	if (!array || size < 2)
		return;

	max = len(array, size);
	for (c = 0; c < max; c++)
	{
		for (i = 0; i < 100; i++)
			Back[i] = 0;

		/*Check B*/
		for (i = 0; i < (int)size; i++)
		{
			r = (array[i] / div) % 10;
			Forward[r][Back[r]] = array[i];
			Back[r] += 1;
		}
		i = 0;
		/*Check F*/
		for (k = 0; k < 100; k++)
		{
			for (j = 0; j < Back[k]; j++)
			{
				array[i] = Forward[k][j];
				i++;
			}
		}
		div *= 10;
		print_array(array, size);
	}
}
