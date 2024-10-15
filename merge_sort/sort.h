#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);

#endif /* SORT_H */
