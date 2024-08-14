#include "search.h"
#include <math.h>
#include <stdint.h>

/**
 * linear_skip - Searches for a value in a sorted skip list using the express lane
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
    skiplist_t *node = head, *express_node = NULL, *last_node = NULL;

    if (head == NULL)
        return NULL;

    /* Traverse the express lane to find the block where the value might be */
    while (node->express && node->express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->express->index, node->express->n);
        node = node->express;
    }

    /* At this point, node is at the beginning of the block to search in */
    express_node = node;
	    /* Find the last node in the list */
    last_node = node;
    while (last_node->next)
        last_node = last_node->next;

    printf("Value found between indexes [%lu] and [%lu]\n",
           express_node->index,
           express_node->express ? express_node->express->index : last_node->index);

    /* Perform linear search in the block from express_node to the end */
    while (express_node && express_node->index <= (express_node->express ? express_node->express->index : last_node->index))
    {
        printf("Value checked at index [%lu] = [%d]\n", express_node->index, express_node->n);
        if (express_node->n == value)
            return express_node;
        express_node = express_node->next;
    }

    return NULL;
}
