#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* counting_sort - Sorts an array of integers in ascending order using the
*                 counting sort algorithm
* @array: The array to be sorted
* @size: The size of the array to be sorted
* Description: Sorts an array of integers in ascending order using the
*              counting sort algorithm
* Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	/* TODO */
	size_t i;
	int counts_size, num, max, j;
	int *counts;

	if (array == NULL || size <= 1) /* Do nothing */
	{
		;
	}
	else
	{
		max = 0;

		/* Find the range */
		for (i = 0; i < size; i++)
		{
			num = array[i];
			if (num > max)
				max = array[i];
		}
		counts_size = max + 1;
		counts = get_count_array(counts_size);

		for (i = 0; i < size; i++) /* fill with frequencies of numbers */
			counts[array[i]]++;

		/* update counts with the actual positions for the output array */
		i = 0;
		for (j = i + 1; j < counts_size; j++, i++)
			counts[j] = counts[i] + counts[j];

		print_array(counts, counts_size); /* print array of positions */

		sort_with_positions(&array, size, &counts);
		free(counts);
	}
}

/**
 * get_count_array - Returns a zero-initialized array to be used for counting
 *                   elements while sorting
 * @k: The size of the array to be returned
 * Description: Returns a zero-initialized array to be used for counting
 *              elements while sorting
 * Return: A zero-initialized array to be used for counting
 *          elements while sorting
*/
int *get_count_array(int k)
{
	int *count_array;
	int i;

	count_array = (int *)malloc(sizeof(int) * (k));
	/* initialize with zeroes */
	for (i = 0; i < k; i++)
	{
		count_array[i] = 0;
	}
	return (count_array);
}

/**
 * sort_with_positions - Sorts, in-place, the numbers in the unsorted array,
 *                       using positions dictated by the a positions array
 * @unsorted: The unsorted array
 * @size: The size of the unsorted array
 * @positions: The array of positions, that dictates where numbers get placed
 *             while they are being sorted
 * Description: Sorts, in-place, the numbers in the unsorted array,
 *              using positions dictated by the a positions array
 * Return: Nothing.
*/
void sort_with_positions(int **unsorted, size_t size, int **positions)
{
	size_t i;
	int j, key, correct_index;
	int *unsorted_copy;

	/* duplicate unsorted array to avoid overwriting while iterating */
	unsorted_copy = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		unsorted_copy[i] = (*unsorted)[i];
	}

	for (j = size - 1; j >= 0; j--)
	{
		key = unsorted_copy[j];
		correct_index = (*positions)[key] - 1;
		(*positions)[key]--;
		(*unsorted)[correct_index] = key;
	}

	free(unsorted_copy);
}
