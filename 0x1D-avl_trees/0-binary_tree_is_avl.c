#include "binary_trees.h"
/**
 * is_tree_valid_avl - check if a given tree is a valid avl
 * @tree: head node of a tree
 * @min_tree_v: minimun value of a subtree
 * @max_tree_v: maximun value of a subtree

 * Return: 1 on valid avl, 0 otherwise
 */
int is_tree_valid_avl(const binary_tree_t *tree, int min_tree_v,
		int max_tree_v, int *height)
{
	int height1 = 0, height2 = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min_tree_v || tree->n >= max_tree_v)
		return (0);

	if (is_tree_valid_avl(tree->left, min_tree_v, tree->n, &height1) == 0 ||
			is_tree_valid_avl(tree->right, tree->n, max_tree_v, &height2) == 0)
		return (0);

	/*select the max value of height*/
	*height = ((height1 > height2) ? height1 : height2) + 1;

	if (abs(height1 - height2) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - check if a given tree is a valid AVL tree
 * @tree: head node of a tree
 * Return: 1 if a given tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_tree_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
