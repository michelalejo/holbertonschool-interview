#include <stdlib.h>
#include "binary_trees.h"


/**
 * heap_insert - Function that inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value store in the node to be inserted.
 * Return: Return a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tmp, *new;

	tmp = heap_search(*root);
	new = binary_tree_node(tmp, value);
	if (new == NULL)
		return (NULL);
	if (tmp == NULL)
		*root = new;
	else if (!(tmp->left))
		tmp->left = new;
	else
		tmp->right = new;
	max_heap_sort(new);
	return (new);
}
/**
 * heap_size - count nodes in a bt
 * @root: double pointer to the root node
 *
 * Return: number of nodes
 */
int heap_size(heap_t *root)
{
	int ctn = 0;

	if (root == NULL)
		return (0);
	ctn += heap_size(root->left) + 1;
	ctn += heap_size(root->right);
	return (ctn);
}

/**
 * tree_is_perfect - function that checks if a tree is perfect
 * @tree: pointer to the root
 * Return: 1 if true or 0 if false
 */

int tree_is_perfect(const heap_t *tree)
{
	int one, two;

	if (tree == NULL)
		return (0);
	one = heap_size(tree->left);
	two = heap_size(tree->right);
	if (one == two)
		return (1);
	return (0);
}

/**
 * heap_search - find the parent to insert a new child
 * @root: double pointer to the root node of the Heap
 *
 * Return: a pointer to the parent node
 */
heap_t *heap_search(heap_t *root)
{
	heap_t *p;
	int l, r, lp, rp;

	if (root == NULL)
	{
		return (NULL);
	}
	p = root;
	l = heap_size(p->left);
	r = heap_size(p->right);
	lp = tree_is_perfect(p->left);
	rp = tree_is_perfect(p->right);
	if (!l || !r)
	{
		return (p);
	}
	if (!lp || (lp && rp && l == r))
	{
		return (heap_search(p->left));
	}
	else if (!rp || (lp && rp && l > r))
	{
		return (heap_search(p->right));
	}

	return (p);
}
