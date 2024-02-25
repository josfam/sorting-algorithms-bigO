#include "sort.h"
#include <stdio.h>

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
*                      order using the Cocktail shaker sort algorithm
* @list: The linked list containing these nodes
* Description: Sorts a doubly linked list of integers in ascending
*              order using the Cocktail shaker sort algorithm
* Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	int list_size, swaps_occurred;
	listint_t *tail;

	list_size = get_list_size(list);

	if (list == NULL || list_size <= 1) /* Do nothing */
	{
		;
	}
	else
	{
		tail = *list;
		while (tail->next) /* find the tail */
			tail = tail->next;

		while (1) /* keep going until no swapping occurred */
		{
			swaps_occurred = swap_forwards(list, &tail);
			if (!swaps_occurred)
				break;
			swaps_occurred = swap_backwards(list, &tail);
			if (!swaps_occurred)
				break;
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
 * swap_forwards - Moves forward through in the linked list, and swaps elements
 *                 using the bubble sort algorithm
 * @head: The head of the linked list
 * @tail: The tail of the linked list
 * Description: Moves forward in the linked list, and swaps elements using
 *              the bubble sort algorithm
 * Return: 1 if a swap was made in the list, 0 otherwise
 */
int swap_forwards(listint_t **head, listint_t **tail)
{
	int swapped;
	listint_t *l_node, *r_node;

	swapped = 0;
	l_node = *head;
	r_node = l_node->next;

	while (r_node != NULL)
	{
		l_node = r_node->prev;

		if (l_node->n > r_node->n)
		{
			swap_nodes_cocktail(l_node, r_node, head, tail);
			swapped = 1;
			print_list(*head);
			r_node = l_node->next;
			continue;
		}
		r_node = r_node->next;
	}

	return (swapped);
}

/**
 * swap_backwards - Moves backwards through the linked list, and swaps elements
 *                  using the bubble sort algorithm
 * @head: The head of the linked list
 * @tail: The tail of the linked list
 * Description: Moves backwards through the linked list, and swaps elements
 *              using the bubble sort algorithm
 * Return: 1 if a swap was made in the list, 0 otherwise
 */
int swap_backwards(listint_t **head, listint_t **tail)
{
	int swapped;
	listint_t *l_node, *r_node;

	swapped = 0;
	r_node = *tail;
	l_node = r_node->prev;

	while (l_node != NULL)
	{
		r_node = l_node->next;

		if (l_node->n > r_node->n)
		{
			swap_nodes_cocktail(l_node, r_node, head, tail);
			swapped = 1;
			print_list(*head);
			l_node = r_node->prev;
			continue;
		}
		l_node = l_node->prev;
	}

	/* move to the end of the list */
	return (swapped);
}

/**
 * swap_nodes_cocktail - Swaps two nodes in a linked list, while considering
 *                       the tail too
 * @left: The first node participating in the swap
 * @right: The second node participating in the swap
 * @head: The head of the linked list
 * @tail: The tail of the linked list containing these nodes
 * Description: Swaps two nodes in a linked list, while considering the tail
 *              too
 * Return: 1 if the swap was successful
 */
int swap_nodes_cocktail(listint_t *left, listint_t *right, listint_t **head,
				listint_t **tail)
{
	left->next = right->next;
	if (right != *tail) /* nothing comes after the tail */
		right->next->prev = left;

	right->next = left;
	right->prev = left->prev;
	if (left != *head) /* nothing comes before the head */
		left->prev->next = right;

	left->prev = right;
	if (right->prev == NULL) /* right is now the head */
		*head = right;

	if (left->next == NULL) /* left must be the tail */
		*tail = left;

	return (1);
}
