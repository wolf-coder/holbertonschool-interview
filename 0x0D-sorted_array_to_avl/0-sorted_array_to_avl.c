#include "binary_trees.h"

/**
 * sorted_array_to_avl - Stores recursively each level in
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t middle = size / 2, i, middle_m = (middle / 2) + 1;
	int idx = 0;

	if (!array || !size)
		return (NULL);

	tree = malloc(sizeof(avl_t));
	if (!tree)
		return (NULL);
	tree->n = array[middle];
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;

	for (i = 1; i < size; i++)
	{

		if (i == 1)
			idx = middle - middle_m;
		else if (i == 2)
			idx = middle + middle_m;
		else if (i == 3)
			idx = middle - (middle_m + (middle_m / 2));
		else if (i == 4)
			idx = middle - (middle_m / 2);
		else if (i == 5)
			idx = middle + (middle_m / 2);
		else if (i == 6)
			idx = middle + (middle_m + (middle_m / 2));
		else if (i == 7)
			idx = middle - middle;
		else
			idx = idx + 2;
		insert_node(&tree, array[idx]);
	}

	return (tree);
}

/**
 * insert_node - Inserts a node in a binary tree
 * @tree: Pointer to the node to insert
 * @value: Value to insert
 *
 * Return: Pointer to the new node
 */

void insert_node(avl_t **tree, int value)
{
	avl_t *new_node;
	avl_t *current;

	if (!tree || !*tree)
		return;

	current = *tree;
	new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return;

	new_node->n = value;
	new_node->parent = current;
	new_node->left = NULL;
	new_node->right = NULL;

	if (current->left == NULL)
		current->left = new_node;
	else if (current->right == NULL)
		current->right = new_node;
	else if (current->left->left == NULL || current->left->right == NULL)
		insert_node(&current->left, value);
	else if (current->right->left == NULL || current->right->right == NULL)
		insert_node(&current->right, value);
	else if (current->left->left->left == NULL ||
			 current->left->left->right == NULL)
		insert_node(&current->left->left, value);
	else if (current->left->right->left == NULL ||
			 current->left->right->right == NULL)
		insert_node(&current->left->right, value);
	else if (current->right->left->left == NULL ||
			 current->right->left->right == NULL)
		insert_node(&current->right->left, value);
	else if (current->right->right->left == NULL ||
			 current->right->right->right == NULL)
		insert_node(&current->right->right, value);
}
