#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: index of first element
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t step, i, min;

	if (array == NULL || size < 2)
		return;
	for (step = 0; step < size - 1; step++)
	{
		min = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		if (min != step)
		{
			swap(array + min, array + step);
			print_array(array, size);
		}
	}
}
/**
 * swap_ints - Swap two integers in an array.
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
