#include "binary_trees.h"

/**
 * sorted_array_to_avl - Slides and merges an array of integers
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (merge_algo(array, 0, size - 1, NULL));
}

/**
 * merge_algo - Uses recursion to sort the nodes of an AVL tree
 * from a sorted array
 * @array: pointer to array containing elements
 * @left_start: start of the left index
 * @right_end: end of the right index
 * @root: pointer to the parent node which is NULL
 * Return: newly created node and it's values
 */
avl_t *merge_algo(int *array, int left_start, int right_end, avl_t *root)
{
	int middle;
	avl_t *tree;

	if (left_start > right_end)
		return (NULL);

	middle = (left_start + right_end) / 2;
	tree = calloc(1, sizeof(avl_t));
	if (tree == NULL)
		return (NULL);

	tree->parent = root;
	tree->left = merge_algo(array, left_start, middle - 1, tree);
	tree->right = merge_algo(array, middle + 1, right_end, tree);
	tree->n = array[middle];

	return (tree);
}
