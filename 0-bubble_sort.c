#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using the Bubble
*               sort algorithm
* @array: The array of integers to sort
* @size: The size of the integer array
* Description: Sorts an array of integers in ascending order using the Bubble
*              sort algorithm
* Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	int swap_was_made, current, neighbour;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		swap_was_made = 0;
		for (j = 0; j < (size - 1) - i; j++)  /* comparisons */
		{
			current = array[j];
			neighbour = array[j + 1];

			/* swap if number is greater than its neighbor */
			if (current > neighbour)
			{
				array[j] = neighbour;
				array[j + 1] = current;
				swap_was_made = 1; /* record this swap */
				print_array(array, size);
			}
		}

		if (!swap_was_made) /* Everything is already sorted */
			break;
	}
}
