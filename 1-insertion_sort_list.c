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

	if (list == NULL || list_size <= 1)
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
				left_node = temp->prev;
				print_list(*list); /* print after every swap */

				if (left_node == NULL) /* no more swaps are needed */
					break;
			}
			current = current->next;
		}
	}
}

/**
* get_list_size - Returns the length of a linked list
* @list: The linked list whose size to return
* Description: Returns the length of a linked list
* Return: The size of the linked list
*/
int get_list_size(listint_t **list)
{
	int size;
	listint_t *current;

	if (list == NULL)
		return 0;

	current = *list;
	size = 0;
	if (list == NULL)
		return (0);

	while (current != NULL)
	{
		size++;
		current = current->next;
	}

	return (size);
}

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @left: The first node participating in the swap
 * @right: The second node participating in the swap
 * @list: The linked list containing these nodes
 * Description: Swaps two nodes in a linked list
 * Return: 1 if the swap was successful
 */
int swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *head;

	head = *list;

	if (left == head && right->next == NULL) /* swapping head and tail */
	{
		head->next = right->next;
		right->prev = head->prev;
		head->prev = right;
		right->next = head;
		*list = right; /* update the list to this new "head" */
		return (1);
	}

	left->next = right->next;
	if (right->next) /* check that right is not a tail */
		right->next->prev = left;

	right->next = left;
	right->prev = left->prev;
	if (left->prev) /* check that left is not the head */
		left->prev->next = right;

	left->prev = right;
	if (right->prev == NULL) /* right is now the head */
		*list = right;

	return (1);
}
