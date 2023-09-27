#include "sort.h"

void quick_sort(int *array, size_t size)
{
	quickSortLomuto(array, 0, size - 1, size);
}

void quickSortLomuto(int *array, int lowerbound, int upperbound, size_t size)
{
	int partition;

	if (lowerbound < upperbound)
	{
		partition = partitionLomuto(array, lowerbound, upperbound, size);

		quickSortLomuto(array, lowerbound, partition - 1, size);
		quickSortLomuto(array, partition + 1, upperbound, size);
	}
}

int partitionLomuto(int *array, int lowerbound, int upperbound, size_t size)
{
	int pivot = array[upperbound];
	int i = lowerbound - 1;
	int current;

	for (current = lowerbound; current <= upperbound - 1; current++)
	{
		if (array[current] <= pivot)
		{
			i++;
			swap(&array[i], &array[current]);
			if (i != current)
				print_array(array, size);

		}
	}
	swap(&array[i + 1], &array[upperbound]);
	if (i + 1 != upperbound)
		print_array(array, size);
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
