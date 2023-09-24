#include "sort.h"
/**
 * bubble_sort - sorts an array using buuble sort
 * @array: address of first element
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, len = size;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < len - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
/**
 * swap - performs the swap for the two integers
 * @a: address of greater than integer
 * @b: address of lesser than integer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
