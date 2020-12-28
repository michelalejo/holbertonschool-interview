#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	heap_t *BeforeNode = NULL, *AfterNode = NULL;
	size_t bitwised = 0, size = 0;
	int value = 0;

	size = treesize(*root);
	if (!root || size == 0)
		return (0);

	bitwised = bitwise(size) >> 1;
	if (size == 1)
	{
		value = (*root)->n;
		free(*root), *root = NULL;
		return (value);
	}

	for (BeforeNode = *root; bitwised; bitwised >>= 1)
		BeforeNode = (bitwised & size) ? BeforeNode->right : BeforeNode->left;

	value = (*root)->n;
	(*root)->n = BeforeNode->n;
	AfterNode = BeforeNode->AfterNode, free(BeforeNode);
	if ((size--) & 1)
		AfterNode->right = NULL;
	else
		AfterNode->left = NULL;

	restore(*root);
	return (value);
}

/**
 * treesize - Recursive funtion to get the size of a tree.
 * @root: Pointer to the root of the tree.
 * Return: The size of the tree.
 */
size_t treesize(heap_t *root)
{
	if (!root)
		return (0);

	return (treesize(root->left) + treesize(root->right) + 1);
}

/**
 * bitwise - Set bity for the given number
 * @number: Number to be set.
 * Return: The given number set.
 */
size_t bitwise(size_t number)
{
	number |= number >> 1;
	number |= number >> 2;
	number |= number >> 4;
	number |= number >> 8;
	number |= number >> 16;
	number = number + 1;
	return (number >> 1);
}

/**
 * restore - Restore the tree down from the root.
 * @root: Pointer to the tree.
 * Return: None it's void.
 */
void restore(heap_t *root)
{
	int tmp;
	heap_t *temp = root, *child = NULL;

	while (1)
	{
		if (!temp->left)
			break;
		if (!temp->right)
			node = temp->left;
		else
			node = (temp->left->n - temp->right->n) >= 0
						? temp->left
						: temp->right;
		if ((temp->n - node->n) > 0)
			break;
		tmp = temp->n;
		temp->n = node->n;
		node->n = tmp;
		temp = node;
	}
}
