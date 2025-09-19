#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}

/**
 * merge_sort_recursive - Recursively splits and sorts the array.
 * @array: The array being sorted.
 * @temp: Temporary buffer used for merging.
 * @left: Left index.
 * @right: Right index.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t mid = left + (right - left + 1) / 2;

	merge_sort_recursive(array, temp, left, mid - 1);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge - Merges two sorted halves into one sorted segment.
 * @array: The array being sorted.
 * @temp: Temporary buffer used for merging.
 * @left: Left index.
 * @mid: Middle index.
 * @right: Right index.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid + 1);

	while (i < mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
