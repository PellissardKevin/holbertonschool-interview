#include "search_algos.h"

/**
 * print_array - Print the current subarray
 * @array: Pointer to the first element of the array
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 *
 * Description: This function prints the current subarray from index
 * left to right.
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++) {
        printf("%d", array[i]);
        if (i != right)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - Helper function for the advanced binary search
 * @array: Pointer to the first element of the array
 * @left: The left boundary of the subarray
 * @right: The right boundary of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value) {
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (recursive_binary(array, left, mid - 1, value));
    } else if (array[mid] > value) {
        return (recursive_binary(array, left, mid, value));
    } else {
        return (recursive_binary(array, mid + 1, right, value));
    }
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (recursive_binary(array, 0, size - 1, value));
}
