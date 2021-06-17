#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL tree from an array
 * @array: array
 * @size: size
 * Return:  Pointer to the root node
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node, *rightNode, *leftNode = NULL;
	size_t half;

	if (size == 0 || !array)
		return (NULL);

	node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	half = (size - 1) / 2;
	node->n = array[half];
	node->parent = NULL;

	if (half > 0)
		leftNode = sorted_array_to_avl(array, half);

	else
		leftNode = NULL;

	if (size > (half + 1))
		rightNode = sorted_array_to_avl(&array[half + 1], size - (half + 1));

	else
		rightNode = NULL;

	node->left = leftNode;
	node->right = rightNode;

	if (node->left)
		(node->left)->parent = node;

	if (node->right)
		(node->right)->parent = node;

	return (node);
}
