#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_last_node - find last node using level-order traversal (BFS)
 * @root: pointer to heap root
 * Return: pointer to last node
 */
static heap_t *get_last_node(heap_t *root)
{
	heap_t **queue, *node;
	size_t front = 0, back = 0, size = 1024;

	if (!root)
		return (NULL);

	queue = malloc(sizeof(*queue) * size);
	if (!queue)
		return (NULL);

	queue[back++] = root;
	while (front < back)
	{
		node = queue[front++];
		if (node->left)
			queue[back++] = node->left;
		if (node->right)
			queue[back++] = node->right;
	}
	free(queue);
	return (node);
}

/**
 * heapify_down - restore max heap property
 * @node: pointer to heap node
 */
static void heapify_down(heap_t *node)
{
	heap_t *bigger_child;
	int temporary;

	if (!node)
		return;

	while (node->left || node->right)
	{
		bigger_child = node;
		if (node->left && node->left->n > bigger_child->n)
			bigger_child = node->left;
		if (node->right && node->right->n > bigger_child->n)
			bigger_child = node->right;

		if (bigger_child == node)
			break;

		temporary = node->n;
		node->n = bigger_child->n;
		bigger_child->n = temporary;

		node = bigger_child;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to heap root
 * Return: value of extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *root_node, *last;
	int extracted_value;

	if (!root || !*root)
		return (0);

	root_node = *root;
	extracted_value = root_node->n;

	if (!root_node->left && !root_node->right)
	{
		free(root_node);
		*root = NULL;
		return (extracted_value);
	}

	last = get_last_node(root_node);
	root_node->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(root_node);

	return (extracted_value);
}
