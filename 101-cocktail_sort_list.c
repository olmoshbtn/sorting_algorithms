#include "sort.h"

/**
 * swap_node - swaps a node with the next node in the list
 * @list: double pointer to the head of a doubly linked list
 * @node: pointer to the node to swap
 */
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doube pointer to head of the doubly linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	/* Boolean values, true equals 1, false equals 0 */
	char swapped = 1;
	listint_t *tmp = *list;

	if (list == NULL || *list == NULL)
		return;

	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_node(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
			tmp = tmp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_node(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
