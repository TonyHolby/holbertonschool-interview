#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev;

	if (list == NULL)
		return (NULL);

	node = list;

	while (node->express && node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
		node = node->express;
	}

	if (node->express)
	{
		prev = node;
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);
	}
	else
	{
		prev = node;
		while (node->next)
			node = node->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);
	}

	return (search_range(prev, node, value));
}

/**
 * search_range - performs linear search between two skiplist nodes
 * @start: pointer to the start node
 * @end: pointer to the end node
 * @value: value to search for
 *
 * Return: pointer to the node containing value, or NULL
 */
skiplist_t *search_range(skiplist_t *start, skiplist_t *end, int value)
{
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
