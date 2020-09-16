#include "lists.h"

/**
 * check_cycle - Function in C that checks if a singly linked list has a cycle.
 * @list: Linked list.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *node = NULL, *lnode = NULL;

	if (!list)
		return (0);

	node = list;
	lnode = node->next;
	while (lnode && lnode->next && lnode->next->next)
	{
		if (node == lnode)
		return (1);
		node = node->next;
		lnode = lnode->next->next;
	}
	return (0);
}
