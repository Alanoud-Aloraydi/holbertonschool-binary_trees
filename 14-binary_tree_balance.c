#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree. If tree is NULL, returns 0.
 * Note: A single node (leaf) returns 1 in this implementation
 * to allow for correct balance factor calculation.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* if node is NULL, it has no height */
	if (tree == NULL)
		return (0);

	/* Recursively find the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);


	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The balance factor (Left Height - Right Height).
 * If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree)
	{
		/**
		 *  Cast to (int) to ensure the result can be negative
		 *  Store heights in variables to keep return line under 80 chars
		 */
		left = (int)binary_tree_height(tree->left);
		right = (int)binary_tree_height(tree->right);

		return (left - right);
	}

	return (0);
}
