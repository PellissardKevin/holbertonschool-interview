#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * getMax - Gets the maximum value in an array
 *
 * @arr: Array to find the max value in
 * @n: Size of the array
 * Return: The maximum integer in the array
 */
int getMax(int *arr, size_t n)
{
	int mx = arr[0];
	size_t i;

	for (i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];

	return (mx);
}

/**
 * countSort - Performs counting sort on an array according to a specific digit
 *
 * @arr: Array to sort
 * @n: Size of the array
 * @exp: The current digit position to sort by (1, 10, 100, ...)
 */
void countSort(int *arr, size_t n, int exp)
{
	int *output = malloc(n * sizeof(int));
	int count[10] = {0};
	size_t i;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n; i-- > 0;)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD (Least Significant Digit) Radix Sort algorithm
 *
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int m = getMax(array, size);

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
