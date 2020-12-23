#include "sort.h"

/**
 * max_heap - Arr ordered with Max Heap Algorithm.
 * @arr: Array of integer.
 * @index: Current index to be change
 * @size: Complete size of the array.
 * @len: Len.
 */
void max_heap(int *arr, int index, int size, int len)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int max = index;

	if (left > 0 && left < len && arr[left] > arr[max])
	{
		max = left;
	}
	if (right > 0 && right < len && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != index)
	{
		swap_(arr + max, arr + index);
		print_array(arr, size);
		max_heap(arr, max, size, len);
	}
}

/**
 * swap_ - Funtion to swap between two values.
 * @i: integer to swap
 * @j: integer to swap
 */
void swap_(int *i, int *j)
{
	*i = *i * *j;
	*j = *i / *j;
	*i = *i / *j;
}

/**
 * heap_sort - Sort arr of integers ascending order with Heap Sort algorithm.
 * @arr: arr of integers to sort
 * @size: Size of the ar
 */
void heap_sort(int *arr, size_t size)
{
	int i = (size / 2) - 1;
	int j = size - 1;

	while (i >= 0)
	{
		max_heap(arr, i, size, size);
		i--;
	}

	while (j > 0)
	{
		swap_(arr + j, arr);
		print_array(arr, size);
		max_heap(arr, 0, size, j);
		j--;
	}
}
