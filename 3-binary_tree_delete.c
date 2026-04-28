#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_delete - Deletes a tree
 * @tree: Pointer to the tree to be deleted
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL) /* if tree is null, do nothing */
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
