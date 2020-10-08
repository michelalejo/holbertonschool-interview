#include "binary_trees.h"

/**
 * heap_insert - Inserts a new Node
 * @root: root node
 * @value: value to insert
 * Return: The new allocated node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *min = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}
	min = free_space(*root);

	if (!min->left)
		min->left = new_node;
	else
		min->right = new_node;

	new_node->parent = min;
	return (swap_nodes(new_node));
}

/**
 * free_space - Inserts the new node in a free child
 * @root: Root node
 * Return: A pointer to the new node
 */
heap_t *free_space(heap_t *root)
{
	empty_space_t aux;

	aux = find_space(root);
	return (aux.node);
}

/**
 * swap_nodes - Changes the new node position to his real one
 * @node: Node to change position
 * Return: The new position of the node
 */
heap_t *swap_nodes(heap_t *node)
{
	int swap_aux;
	heap_t *iterator = node;

	while (iterator->parent)
	{
		if (iterator->n > iterator->parent->n)
		{
			swap_aux = iterator->n;
			iterator->n = iterator->parent->n;
			iterator->parent->n = swap_aux;

			iterator = iterator->parent;
			continue;
		}
		return (iterator);
	}
	return (iterator);
}

/**
 * find_space - Finds the space at the left
 * @node: Parent node
 * Return: An struct with the node and the deep
 */
empty_space_t find_space(heap_t *node)
{
	empty_space_t l, r, aux;

	aux.node = node;
	aux.deep = 0;

	if (!node->left || !node->right)
	{
		return (aux);
	}

	l = find_space(node->left);
	r = find_space(node->right);

	if (l.deep <= r.deep)
	{
		l.deep += 1;
		return (l);
	}
	else
	{
		r.deep += 1;
		return (r);
	}
}
