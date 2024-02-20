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
