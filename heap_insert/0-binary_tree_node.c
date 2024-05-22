#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	heap_t *new_node = (heap_t *)malloc(sizeof(heap_t));
	if (new_node == NULL)
	{
		return NULL; // Memory allocation failed
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}
