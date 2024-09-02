#include "sort.h"

/**
 * siftDown - maintains the heap property by sifting down
 * an element at a given index
 *
 * @array: the array representing the heap
 * @index: the index of the element to sift down
 * @size: the size of the heap (not the full array size)
 */
void siftDown(int *array, int index, size_t size)
{
    int largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    int temp;

    // If the left child is larger than the root
    if (left < size && array[left] > array[largest])
    {
        largest = (int)left;
    }

    // If the right child is larger than the largest so far
    if (right < size && array[right] > array[largest])
    {
        largest = (int)right;
    }

    // If largest is not the root
    if (largest != index)
    {
        // Swap
        temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;

        // Print the array after each swap
        print_array(array, size);

        // Recursively sift down the affected subtree
        siftDown(array, largest, size);
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

    // Build max heap
    for (int i = (int)(size / 2) - 1; i >= 0; i--)
    {
        siftDown(array, i, size);
    }

    // Extract elements from the heap one by one
    for (int i = (int)(size - 1); i > 0; i--)
    {
        // Move current root (max) to the end
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Print the array after each swap
        print_array(array, size);

        // Call siftDown on the reduced heap
        siftDown(array, 0, i);
    }
}
