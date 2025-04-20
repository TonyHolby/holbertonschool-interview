#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap.
 *
 * @root: a double pointer to the root node of the Heap.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	int count = count_nodes(*root);
	heap_t *parent = get_insertion_parent(*root, count);
	heap_t *new_node = binary_tree_node(parent, value);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heap_t *current = new_node;

	while (current->parent && current->n > current->parent->n)
	{
		swap_values(current, current->parent);
		current = current->parent;
	}

	return (new_node);
}

/**
 * swap_values - a function that swaps two nodes.
 *
 * @node_a: the first node.
 * @node_b: The second node.
 */

void swap_values(heap_t *node_a, heap_t *node_b)
{
	int tmp = node_a->n;

	node_a->n = node_b->n;
	node_b->n = tmp;
}

/**
 * count_nodes - Recursively counts the total number of nodes.
 *
 * @root: A pointer to the root node of the heap.
 *
 * Return: The total number of nodes in the heap.
 */

int count_nodes(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_insertion_parent - Finds the parent node where a new node should be
 * inserted in a complete binary heap.
 *
 * @root: A pointer to the root node of the heap.
 * @index: The current total number of nodes in the heap.
 *
 * Return: A pointer to the parent node where the next insertion should happen.
 */

heap_t *get_insertion_parent(heap_t *root, int index)
{
	int path[32], i = 0;

	index++;

	while (index > 1)
	{
		path[i++] = index % 2;
		index /= 2;
	}

	heap_t *current = root;

	for (int j = i - 1; j > 0; j--)
	{
		if (path[j] == 0)
			current = current->left;
		else
			current = current->right;
	}

	return (current);
}
