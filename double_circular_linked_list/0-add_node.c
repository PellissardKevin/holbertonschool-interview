#include "list.h"

/**
 * add_node_end - add a node at the end of the linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tail;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		tail = (*list)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - add a node at the start of the linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
