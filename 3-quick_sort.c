#include <sort.h>

void quick_sort(int *array, size_t size)
{
	quickSortLomuto(array, 0, size - 1);
}

void quickSortLomuto(int *array, int lowerbound, int upperbound)
{
	int partition;
	if (lowerbound < upperbound)
	{
		partition = partitionLomuto(array, lowerbound, upperbound);

		quickSortLomuto(array, lowerbound, partition - 1);
		quickSortLomuto(array, partition + 1, upperbound);
	}
}

int partition(int *array, int lowerbound, int upperbound)
{
	int pivot = array[upperbound];
	int i = lowerbound - 1;
	int currentIndex;

	for (current = lowerbound; current < upperbound; current++)
	{
		if (array[current] <= pivot)
		{
			i++;
			swap(array[i], array[current]);
		}
	}
	swap(array[i + 1], array[upperbound]);
	return (i + 1);
}
