#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to be checked
 * Return: 1 if left. 0 if not leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
/**
 * binary_tree_height - function that goes through the tree and mesure height
 *@tree: tree to loop through
 *
 *Return: nothing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0, height2 = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left != NULL)
		height = binary_tree_height(tree->left);
	if (tree->right != NULL)
		height2 = binary_tree_height(tree->right);

	if (height > height2)
		return (height + 1);
	else
		return (height2 + 1);
}

/**
 * binary_tree_size - count all child nodes including the root
 * @tree: tree to loop through
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * binary_tree_is_perfect - checks if tree is perfect
 *@tree: tree to check
 *
 *Return: 1 perfect 0 not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, i, j, sum = 0, pow;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	for (i = 0; i <= binary_tree_height(tree); i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		sum += pow;
	}
	if (sum == size)
		return (1);
	return (0);
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: the root node of the tree
 * Return: 1 if is complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);

	left = tree->left;
	right = tree->right;
	l_height = binary_tree_height(left);
	r_height = binary_tree_height(right);

	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_complete(right))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(left) && binary_tree_is_perfect(right))
			return (1);
	}

	return (0);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	heap_t *new_node = binary_tree_node(NULL, value);

	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	heap_t *parent = *root;

	while (parent->left && parent->right)
		parent = (binary_tree_is_perfect(parent) ||
				  binary_tree_is_complete(parent))
					 ? parent->left
					 : parent->right;

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int temp = new_node->parent->n;

		new_node->parent->n = new_node->n;
		new_node->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}
