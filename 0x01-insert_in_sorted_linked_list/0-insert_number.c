#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *node_change, *iterator = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	if (!head)
	{
		(*head) = new_node;
		return (new_node);
	}
	if (number < (*head)->n)
	{
		new_node->next = (*head);
		(*head) = new_node;
		return (new_node);
	}

	node_change = iterator;
	while (iterator->next)
	{
		if (number < iterator->n && number >= node_change->n)
		{
			new_node->next = iterator;
			node_change->next = new_node;
			return (new_node);
		}
		node_change = iterator;
		iterator = iterator->next;
	}
	iterator->next = new_node;
	return (new_node);
}
