#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void siftDown(int *array, int index, size_t size, size_t full_size);

#endif /* SORT_H */
