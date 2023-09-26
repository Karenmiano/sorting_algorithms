#include "sort.h"

void quick_sort(int *array, size_t size)
{
	quickSortLomuto(array, 0, size - 1);
}

void quickSortLomuto(int *array, size_t lowerbound, size_t upperbound)
{
	size_t partition;
	if (lowerbound < upperbound)
	{
		partition = partitionLomuto(array, lowerbound, upperbound);

		quickSortLomuto(array, lowerbound, partition - 1);
		quickSortLomuto(array, partition + 1, upperbound);
	}
}

size_t partitionLomuto(int *array, size_t lowerbound, size_t upperbound)
{
	int pivot = array[upperbound];
	size_t i = lowerbound - 1;
	size_t current;

	for (current = lowerbound; current < upperbound; current++)
	{
		if (array[current] <= pivot)
		{
			i++;
			swap(array + i, array + current);
		}
	}
	swap(array + i + 1, array + upperbound);
	return (i + 1);
}
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
