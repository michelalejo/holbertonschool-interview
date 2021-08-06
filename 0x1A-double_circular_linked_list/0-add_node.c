#include "list.h"

/**
 * add_node_begin - Add a new node at the beggining
 * @list: list
 * @str: string
 * Return: &node
 */

List *add_node_begin(List **list, char *str)
{
	List *new = add_node_end(list, str);

	if (new == NULL)
		return (NULL);
	(*list) = new;
	return (new);
}

/**
 * add_node_end - Add a new node at the end
 * @list: list
 * @str: string
 * Return: &node
 */

List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (new->str == NULL)
		return (NULL);

	if ((*list) == NULL)
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
		return (new);
	}

	new->next = (*list);
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	return (new);
}
