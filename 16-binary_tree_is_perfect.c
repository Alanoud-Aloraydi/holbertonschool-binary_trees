#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * check_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 * @height: Height of the tree
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int check_perfect(const binary_tree_t *tree, size_t height, size_t level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (level == height);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfect(tree->left, height, level + 1) &&
		check_perfect(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_perfect(tree, tree_height(tree), 0));
}
