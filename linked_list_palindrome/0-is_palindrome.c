#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
 * @head: Pointer to the start of the linked list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

/**
 * find_middle - Finds the middle of the linked list.
 * @head: Pointer to the start of the linked list.
 * @prev_slow: Double pointer to the node before the middle.
 * Return: Pointer to the middle node.
 */
listint_t *find_middle(listint_t *head, listint_t **prev_slow)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		*prev_slow = slow;
		slow = slow->next;
	}
	return (slow);
}

/**
 * compare_halves - Compares the two halves of the linked list.
 * @first_half: Pointer to the first half of the list.
 * @second_half: Pointer to the reversed second half of the list.
 * Return: 1 if both halves are identical, otherwise 0.
 */
int compare_halves(listint_t *first_half, listint_t *second_half)
{
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
			return (0);
		first_half = first_half->next;
		second_half = second_half->next;
	}
	return (1);
}

/**
 * restore_list - Restores the original order of the linked list.
 * @prev_slow: Pointer to the node before the middle.
 * @mid_node: Pointer to the middle node (if exists).
 * @second_half: Pointer to the reversed second half of the list.
 */
void restore_list(listint_t *prev_slow, listint_t *mid_node,
				  listint_t *second_half)
{
	second_half = reverse_list(second_half);
	if (mid_node != NULL)
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
	{
		prev_slow->next = second_half;
	}
}

/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * @head: Double pointer to the start of the linked list.
 * Return: 1 if the list is a palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *prev_slow = NULL, *mid_node = NULL, *second_half = NULL;
	listint_t *middle = NULL;
	int result = 1;

	if (!head || !*head)
		return (1);

	if ((*head)->next == NULL)
		return (1);

	middle = find_middle(*head, &prev_slow);

	if (middle != NULL)
	{
		if (middle->next != NULL)
		{
			mid_node = middle;
			middle = middle->next;
		}
		second_half = reverse_list(middle);
		result = compare_halves(*head, second_half);
		restore_list(prev_slow, mid_node, second_half);
	}
	return (result);
}
