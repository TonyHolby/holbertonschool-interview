#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst_util - Utility function to check if tree is a valid BST.
 *
 * @tree: A pointer to the root node.
 * @min: A pointer to minimum value or NULL if no limit.
 * @max: A pointer to maximum value or NULL if no limit.
 *
 * Return: 1 if valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, const int *min, const int *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= *min)
		return (0);

	if (max != NULL && tree->n >= *max)
		return (0);

	return (is_bst_util(tree->left, min, &tree->n) &&
		is_bst_util(tree->right, &tree->n, max));
}

/**
 * is_avl_helper - Helper function to check if tree is a valid AVL.
 *
 * @tree: A pointer to the root node.
 * @min: A pointer to minimum value or NULL if no limit.
 * @max: A pointer to maximum value or NULL if no limit.
 *
 * Return: 1 if valid AVL, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, const int *min, const int *max)
{
	int left_height, right_height, balance;

	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= *min)
		return (0);

	if (max != NULL && tree->n >= *max)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	balance = left_height - right_height;
	if (balance > 1 || balance < -1)
		return (0);

	return (is_avl_helper(tree->left, min, &tree->n) &&
		is_avl_helper(tree->right, &tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, NULL, NULL));
}
