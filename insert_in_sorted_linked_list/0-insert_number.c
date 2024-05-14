#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node
 *
 * @head: pointer to head of list
 * @number: the value
 * Return the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode = malloc(sizeof(listint_t));
	listint_t *current;

	if (newNode == NULL)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;

	if (head == NULL || (*head)->n >= number)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	current = *head;
	while (current->next != NULL && current->next->n < number)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;

	return (newNode);
}
