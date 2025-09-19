#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of element in the array.
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

	size_t mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
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
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, left, mid);
	printf("[right]: ");
	print_subarray(array, mid + 1, right);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_subarray(array, left, right);
}

/**
 * print_subarray - Affiche une portion du tableau.
 * @array: the array being sorted.
 * @start: the index of the first element.
 * @end: the index of the last element.
 */
void print_subarray(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
