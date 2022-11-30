#include "binary_trees.h"
/**
 * is_tree_valid_avl - check if a given tree is a valid avl tree
 * @tree: head node of a tree
 * @max_tree_v: maximun value of a subtree
 * @min_tree_v: minimun value of a subtree
 * @height: The tree height
 * Return: 1 on valid avl, and 0 otherwise
 */
int is_tree_valid_avl(const binary_tree_t *tree, int min_tree_v,
		int max_tree_v, int *height)
{
	/*Initializing the heights*/
	int H1 = 0, H2 = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min_tree_v || tree->n >= max_tree_v)
		return (0);

	if (is_tree_valid_avl(tree->left, min_tree_v, tree->n, &H1) == 0 ||
			is_tree_valid_avl(tree->right, tree->n, max_tree_v, &H2) == 0)
		return (0);

	*height = ((H1 > H2) ? H1 : H2) + 1;

	if (abs(H1 - H2) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - check if a given tree is a valid AVL tree
 * @tree: head node
 * Return: 1 if a given tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_tree_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
