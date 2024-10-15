#include "sort.h"

/**
 * merge_sort - function that sorts an array of integers in ascending order using the Merge Sort algorithm
 *
 * @array: the array to merge sort
 * @size: the size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	if (size <= 1)
		return;

	if (left == NULL || right == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	for (size_t i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (size_t i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);

	merge(array, left, right, mid, size - mid);
	
	printf("[Done]: ");
	print_array(array, size);

	free(left);
	free(right);
}

/**
 * merge - merges two sorted subarrays into one sorted array
 * @array: the original array where the merged result will be placed
 * @left: the left sorted subarray
 * @right: the right sorted subarray
 * @left_size: size of the left subarray
 * @right_size: size of the right subarray
 *
 * Return: void
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		}
		else
		{
			array[k++] = right[j++];
		}
	}

	while (i < left_size)
	{
		array[k++] = left[i++];
	}

	while (j < right_size)
	{
		array[k++] = right[j++];
	}
}
