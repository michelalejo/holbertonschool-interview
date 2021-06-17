#include "sort.h"

/**
 * merge - merges the copied array into the original one
 * @array: array of integers to sort 
 * @tmp: tmp of the array
 * @left: left index beginning of array;
 * @right: right index end of array;
 * @mid: half
 */
void merge(int *array, int *tmp, int left, int right, int mid)
{
    int start, end, i = left;

    start = left;
    end = mid;
    printf("Merging...\n");
    printf("[left]: ");
    print_array(tmp + left, mid - left);
    printf("[right]: ");
    print_array(tmp + mid, right - mid);
    while (start < mid && end < right)
    {
        if (tmp[start] < tmp[end])
        {
            array[i] = tmp[start];
            start++;
        }
        else
        {
            array[i] = tmp[end];
            end++;
        }
        i++;
    }
    while (start < mid)
    {
        array[i] = tmp[start];
        i++;
        start++;
    }
    while (end <= right)
    {
        array[i] = tmp[end];
        i++;
        end++;
    }
    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_split - splits an array in half
 * @array: array to sort
 * @tmp: tmp of the array to sort
 * @left: left the beggining of the array
 * @right: right the end of the array
 */
void merge_split(int *array, int *tmp, int left, int right)
{
    int mid = left + (right - left) / 2;

    if (right - left <= 1)
    {
        return;
    }

    merge_split(tmp, array, left, mid);
    merge_split(tmp, array, mid, right);
    merge(array, tmp, left, right, mid);
}

/**
 * merge_sort - sorts an array by implementing top down merge sort.
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;
    size_t i = 0;

    if (!array || size < 2)
        return;

    tmp = malloc(size * sizeof(int));
    if (!tmp)
        return;
    for (; i < size; i++)
    {
        tmp[i] = array[i];
    }

    merge_split(array, tmp, 0, size);
    free(tmp);
}