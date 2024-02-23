#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly-linked of integers in ascending order
*                       using Insertion sort algorithm
* @list: The doubly-linked list to sort
* Description: Sorts a doubly-linked of integers in ascending order
*              using Insertion sort algorithm
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	int list_size;
	listint_t *head, *current, *left_node, *temp;

	list_size = get_list_size(list);

	if (list == NULL || list_size == 1)
	{
		/* Do nothing */
		;
	}
	else
	{
		head = *list;
		current = head->next;
		while (current != NULL)
		{
			left_node = current->prev;
			temp = current;

			while (left_node != NULL && (left_node->n > temp->n))
			{
				temp = current;
				swap_nodes(left_node, temp, list);
				/* fix pointers that moved after nodes were swapped */
				print_list(*list);
				left_node = temp->prev;
				if (left_node == NULL) /* no more swaps are needed */
					break;
			}
			current = current->next;
		}
	}
}
