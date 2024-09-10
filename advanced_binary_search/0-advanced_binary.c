#include "search_algos.h"


/**
 * print_array - function to print the current subarray
 * @array: pointer to the first element of the array
 * @left: starting index of the subarray
 * @right: ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i != right)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - helper function for the advanced binary search
 * @array: pointer to the first element of the array
 * @left: the left boundary of the subarray
 * @right: the right boundary of the subarray
 * @value: the value to search for
 *
 * Return: the index of the first occurrence of the value, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    if (left > right)
        return -1;

    print_array(array, left, right);

    size_t mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        /* Check if it's the first occurrence */
        if (mid == left || array[mid] != value)
            return mid;
        /* Continue searching in the left half */
        return recursive_binary(array, left, mid, value);
    }
    else if (array[mid] > value)
        return recursive_binary(array, left, mid - 1, value);
    else
        return recursive_binary(array, mid + 1, right, value);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return recursive_binary(array, 0, size - 1, value);
}
