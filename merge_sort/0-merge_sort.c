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
	int *temp = malloc(size * sizeof(int));

	if (size <= 1)
		return;

	if (temp == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}

/**
 * merge_sort_recursive - recursive function for merge sort
 * @array: the array to sort
 * @temp: temporary array used for merging
 * @start: the starting index of the subarray to sort
 * @end: the ending index of the subarray to sort
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	if (start >= end)
		return;

	size_t mid = (start + end) / 2;

	merge_sort_recursive(array, temp, start, mid);
	merge_sort_recursive(array, temp, mid + 1, end);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start + 1);
	printf("[right]: ");
	print_array(array + mid + 1, end - mid);

	merge(array, temp, start, mid, end);

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}

/**
 * merge - merges two sorted subarrays into one sorted array
 * @array: the original array where the merged result will be placed
 * @temp: temporary array used during merging
 * @start: the starting index of the left subarray
 * @mid: the ending index of the left subarray and mid-point of the array
 * @end: the ending index of the right subarray
 *
 * Return: void
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid + 1, k = start;

	// Copy array into temp for merging
	for (size_t t = start; t <= end; t++)
		temp[t] = array[t];

	while (i <= mid && j <= end)
	{
		if (temp[i] <= temp[j])
			array[k++] = temp[i++];
		else
			array[k++] = temp[j++];
	}

	while (i <= mid)
		array[k++] = temp[i++];

	while (j <= end)
		array[k++] = temp[j++];
}
