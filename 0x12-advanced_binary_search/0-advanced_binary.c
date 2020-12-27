#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: Is a pointer to the first element of the array to search.
 * @size: Is the number of elements in array.
 * @value: Is the value to search for.
 * Return: return the index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int temp = 1;
	size_t i = 0, j = 0, result = 0;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	result = (size - 1) / 2;
	if (array[result] == value)
	{
		if (size == 1 || array[result - 1] < value)
			return (result);
	}
	else if (size == 1)
	{
		return (-1);
	}

	if (array[result] < value)
	{
		j += result + 1, array += result + 1;
		if (size % 2 != 0)
			result--;
	}
	result++;

	temp = advanced_binary(array, result, value);
	if (temp != -1)
		return (temp + j);
	return (-1);
}
