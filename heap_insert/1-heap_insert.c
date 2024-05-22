#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_insertion_point - Finds the next insertion point in the heap
 * @root: Root of the heap
 * Return: Pointer to the node where the new node should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
	if (root == NULL)
	{
		return (NULL);
	}

	heap_t **queue = malloc(1024 * sizeof(heap_t *));

	if (!queue)
	{
		return (NULL);
	}
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (current->left == NULL || current->right == NULL)
		{
			free(queue);
			return (current);
		}

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heapify_up - Maintains the Max Heap property by moving the node up
 * @node: The node to heapify up
 */
void heapify_up(heap_t *node)
{
	while (node->parent != NULL && node->n > node->parent->n)
	{
		int temp = node->n;

		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (root == NULL)
	{
		return (NULL);
	}

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	heap_t *insertion_point = find_insertion_point(*root);

	if (insertion_point == NULL)
	{
		return (NULL);
	}

	heap_t *new_node = binary_tree_node(insertion_point, value);

	if (new_node == NULL)
	{
		return (NULL);
	}

	if (insertion_point->left == NULL)
	{
		insertion_point->left = new_node;
	}
	else
	{
		insertion_point->right = new_node;
	}

	heapify_up(new_node);
	return (new_node);
}
