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
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *tmp = *head;

	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (tmp->next == NULL)
	{
		if (tmp->n < number)
		{
			tmp->next = new;
			return (tmp);
		}
		new->next = tmp;
		return (new);
	}
	while(tmp->next)
	{
		if (tmp->next->n > number)
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}
	*head = new;
	return (new);
}
