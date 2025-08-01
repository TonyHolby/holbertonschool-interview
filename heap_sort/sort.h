#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heapify(int arr[], size_t size, int n, int i);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
