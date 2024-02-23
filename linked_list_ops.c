#include "sort.h"

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
