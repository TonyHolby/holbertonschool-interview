#include "sort.h"

/**
 * get_max - Returns the maximum number in the array.
 * @array: the array of integers
 * @size: the size of the array
 * Return: the maximum integer
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t index;

    for (index = 1; index < size; index++)
    {
        if (array[index] > max)
            max = array[index];
    }

    return (max);
}

/**
 * counting_sort_radix - Performs counting sort based on the digit
 *                       represented by digit_position.
 * @array: the array to sort.
 * @size: the size of the array.
 * @digit_position: the current digit position (units, tens, hundreds, ...).
 */
void counting_sort_radix(int *array, size_t size, int digit_position)
{
    int *sorted_array = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t index;

    if (!sorted_array)
        return;

    for (index = 0; index < size; index++)
        count[(array[index] / digit_position) % 10]++;

    for (index = 1; index < 10; index++)
        count[index] += count[index - 1];

    for (index = size; index > 0; index--)
    {
        int current_value = array[index - 1];
        int digit = (current_value / digit_position) % 10;
        int position = count[digit] - 1;

        sorted_array[position] = current_value;
        count[digit]--;
    }

    for (index = 0; index < size; index++)
        array[index] = sorted_array[index];

    free(sorted_array);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using LSD radix sort.
 * @array: the array to sort.
 * @size: the size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}
