#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order using the
*                  selection sort algorithm
* @array: The array of integers to sort
* @size: The size of the integer array
* Description: Sorts an array of integers in ascending order using the
*              selection sort algorithm
* Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min, other, temp;

	if (array == NULL || size == 1) /* do nothing */
	{
		;
	}

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			other = array[j];
			if (other < min)
			{
				min = other;
				min_index = j;
			}
		}
		/* Do a swap if a more minimum value was found */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = min;
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
