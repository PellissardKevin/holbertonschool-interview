#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head;
	listint_t *slow = head;
	int counter = 0;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow->n = counter;
			return slow;
		}
		counter++;
	}
	return NULL;
}
