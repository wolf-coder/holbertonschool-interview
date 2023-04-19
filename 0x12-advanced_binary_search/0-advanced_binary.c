#include "search_algos.h"

/**
 * advanced_binary - Search for a value in a sorted array
 * using recursive binary search
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: The index of the first occurrence
 * of the value in the array or -1 if the value is not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start;
	size_t end;

	if (!array)
		return (-1);

	start = 0;
	end = size - 1;
	return (recursive_search(array, start, end, value));

}

/**
 * array_print - Print a given sub-array of an array
 *
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the sub-array to printSize of array
 * @end: Value to find
 * Return: void
 */
void array_print(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}



/**
 * recursive_search - Recursive advanced binary search algorithms
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the sub-array to search
 * @end: Index of the last element of the sub-array to search
 * @value: Value to search for
 * Return: The index of the first occurrence of the value
 * in the sub-array or -1 if the value is not found
 */
int recursive_search(int *array, size_t start, size_t end, int value)
{
	size_t half;

	if (start < end)
	{
		half = start + (end - start) / 2;
		array_print(array, (int)start, (int)end);
		if (array[half] >= value)
			return (recursive_search(array, start, half, value));
		else
			return (recursive_search(array, half + 1, end, value));
		return ((int)(half));
	}
	if (array[start] == value)
		return (start);
	array_print(array, (int)start, (int)end);
	return (-1);
}
