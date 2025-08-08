#include "search_algos.h"

/**
 * advanced_binary - Calls the function search_value
 *
 * @array: A pointer to the first element of the array
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The index of the value or -1 if failed
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (size == 1)
		return (1);

	if (array == NULL || size == 0)
		return (-1);

	int start = 0;
	int end = size - 1;

	return search_value(array, start, end, value);
}

/**
 * search_value - Searches for a value in a sorted array of integers
 *
 * @array: A pointer to the first element of the array
 * @start: The index of the first element
 * @end: The index of the last element
 * @value: The value to search for
 * Return: The index of the value or -1 if failed
 */
int search_value(int *array, int start, int end, int value)
{
	if (end >= start)
	{
		int half = start + (end - start) / 2;

		printf("Searching in array: ");
		for (int i = start; end >= i; i++)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(", ");
		}
		printf("\n");

		if (array[half] == value && array[half - 1] != value)
			return (half);

		if (array[half] >= value)
			return (search_value(array, start, half, value));

		return (search_value(array, half + 1, end, value));
	}

	return (-1);
}
