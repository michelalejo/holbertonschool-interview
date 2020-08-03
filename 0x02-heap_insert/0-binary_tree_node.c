#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new = malloc(sizeof(binary_tree_t));

    new = malloc(sizeof(binary_tree_t));
    new->n = value;
    new->parent = parent;
    new->left = NULL;
	new->right = NULL;
    return (new);
}
