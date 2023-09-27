#include "sort.h"
/**
 * quick_sort - entry point to quickSortLomuto
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quickSortLomuto(array, 0, size - 1, size);
}
/**
 * quickSortLomuto - sorts an array in ascending order using Lomuto
 * partition scheme
 * @array: array to be sorted
 * @lowerbound: index of the left most element
 * @upperbound: index of right most element
 * @size: size of the array
 *
 * Description: will use recursion to partition the subsets
 */
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
/**
 * partitionLomuto - will partition elements around the pivot element,
 * last element always
 * @array: array/ subset array to partition
 * @lowerbound: left most element
 * @upperbound: right most element considered pivot
 * @size: size of the array
 * Return: index of selected pivot element
 *
 * Description: will print the array any time the position of an element
 * is changed
 */
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
