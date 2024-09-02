#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;

	for (int i = (size/2) - 1; i >= 0; i--)
	{
		siftDown(array, i, size - 1);
	}

	for (int i = size - 1; i >= 1; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		siftDown(array, 0, i - 1);
	}


}

void siftDown(int *array, int index, size_t size)
{
	int k = index, temp;
	size_t j = 2 * k + 1;

	while (j <= size)
	{
		if (j < size && (array[j] < array[j + 1]))
			j++;

		if (array[k] < array[j])
		{
			temp = array[k];
			array[k] = array[j];
			array[j] = temp;

			k = j;
			j = 2 * k + 1;
		}
		else
			break;
	}
}
