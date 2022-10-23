#include "sort.h"
/**

 * @a: first element.
 * @b: second element.
 */
void swap(int *a, int *b)
{

	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * heap_sort - Using the sift-down heap sort algorithm to sort elements.
 * @array: The array.
 * @size: Array size.
 */
void heap_sort(int *array, size_t size)
{
	int i, Tail;

	if (!array || size <= 1)
		return;
	Tail = (int)size - 1;
	for (Tail = (int)size - 1; Tail > 0; Tail--)
	{
		for (i = Tail; i >= 0; i--)
		{
			heapify(array, (int)size, i, Tail);
		}
		swap(&array[0], &array[Tail]);
		print_array((const int *)array, size);
	}
}

/**
 * heapify - Indexing
 * @array: the array.
 * @size: size of the array,
 * @parent: index of the parent node.
 * @last: index.
 */
void heapify(int *array, int size, int parent, int last)
{
	int LEFT, right;

	LEFT = (parent * 2) + 1;
	right = (parent * 2) + 2;
	if (parent < 0 || parent >= size - 1)
		return;
	if (right <= last &&
	(array[right] >= array[LEFT] && array[right] > array[parent]))
	{
		swap(&array[parent], &array[right]);
		print_array((const int *)array, (size_t)size);
		heapify(array, size, right, last);
	}
	if ((LEFT <= last &&
	(right > last || array[LEFT] > array[right])) && array[LEFT] > array[parent])
	{
		swap(&array[parent], &array[LEFT]);
		print_array((const int *)array, (size_t)size);
		heapify(array, size, LEFT, last);
	}
}
