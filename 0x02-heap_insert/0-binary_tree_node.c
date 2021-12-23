#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree.
 * @parent: Pointer to parent node, null in case of root node.
 * @value: value to store in node.
 *
 * Return: pointer to new node, or null if failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *New_node = NULL;

	New_node = malloc(sizeof(binary_tree_t));
	if (!New_node)
		return (NULL);

	New_node->n = value;

	if (!parent)
		return (New_node);

	New_node->parent = parent;
	return (New_node);

}
