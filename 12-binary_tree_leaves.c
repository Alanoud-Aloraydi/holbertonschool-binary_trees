#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the leaves of
 *
 * Return: The number of leaves in the tree, 0 otherwise
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree) /* if tree not NULL */
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0; /* if leaf */
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
