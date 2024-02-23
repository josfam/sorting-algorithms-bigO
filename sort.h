#ifndef SORT_HEADER
#define SORT_HEADER

# include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prints a list of integers */
void print_list(const listint_t *list);

/* Prints an array of integers */
void print_array(const int *array, size_t size);

/* Sorts an array of integers in ascending order using the */
/* Bubble sort algorithm */
void bubble_sort(int *array, size_t size);

/* Sorts an array of integers in ascending order using the*/
/* Insertion sort algorithm */
void insertion_sort_list(listint_t **list);

/* Returns the length of a linked list */
int get_list_size(listint_t **list);

/* Swaps two nodes in a linked list */
int swap_nodes(listint_t *left, listint_t *right, listint_t **list);

#endif
