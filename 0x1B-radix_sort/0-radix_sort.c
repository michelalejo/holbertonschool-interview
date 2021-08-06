#include "sort.h"

/**
 * maxim - Max value.
 * @array: Array.
 * @size: Size.
 * Return: Max value in the array.
 */
int maxim(int *array, size_t size)
{
	size_t mv;
	int maxi = array[0];

	for (mv = 1; mv < size; mv++)
	{
		if (array[mv] > maxi)
			maxi = array[mv];
	}
	return (maxi);
}

/**
 * cnt_sorter - Sorts array with cnt algo.
 * @array: Array-.
 * @size: Size.
 * @key: Key.
 */
void cnt_sorter(int *array, int size, int key)
{
	int *srt = NULL;
	int mv = 0;
	int cnt[10] = {0};

	srt = malloc(sizeof(int) * size);
	if (srt == NULL)
		return;

	for (mv = 0; mv < size; mv++)
		cnt[(array[mv] / key) % 10]++;

	for (mv = 1; mv < 10; mv++)
		cnt[mv] += cnt[mv - 1];

	for (mv = size - 1; mv >= 0; mv--)
	{
		srt[cnt[(array[mv] / key) % 10] - 1] = array[mv];
		cnt[(array[mv] / key) % 10]--;
	}

	for (mv = 0; mv < size; mv++)
		array[mv] = srt[mv];

	free(srt);
	print_array(array, size);
}

/**
 * radix_sort - Sorter using radix algo.
 * @array: Array.
 * @size: Size.
 */
void radix_sort(int *array, size_t size)
{
	int base, maxi, cnt;

	if (array == NULL || size <= 1)
		return;
	maxi = maxim(array, size);
	for (cnt = 1, base = 10; maxi / cnt > 0; cnt *= base)
	{
		cnt_sorter(array, size, cnt);
	}
}
