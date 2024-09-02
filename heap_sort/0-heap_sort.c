#include "sort.h"

/**
 * siftDown - maintains the heap property by sifting down
 * an element at a given index
 *
 * @array: the array representing the heap
 * @index: the index of the element to sift down
 * @size: the size of the heap (not the full array size)
 * @full_size: the full size of the array
 */
void siftDown(int *array, int index, size_t size, size_t full_size)
{
	int largest = index, temp;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
	{
		largest = (int)left;
	}

	if (right < size && array[right] > array[largest])
	{
		largest = (int)right;
	}

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, full_size);

		siftDown(array, largest, size, full_size);
	}
}

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

	for (int i = (int)(size / 2) - 1; i >= 0; i--)
	{
		siftDown(array, i, size, size);
	}

	for (int i = (int)(size - 1); i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		siftDown(array, 0, i, size);
	}
}
