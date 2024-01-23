#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: the doubly linked list
 * Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *check_node, *sorted_node;

	if (*list == NULL || (*list)->next || NULL)
		return;

	/* set head to current */
	current_node = (*list);

	/* loop from the second node to the last node */
	while (current_node != NULL)
	{
		check_node = current_node;
		sorted_node = (*list);
		current_node = current_node->next;

		if (current_node->n > check_node->n)
		{
			while (sorted_node != NULL)
			{
				/* loop and inserted in the sorted part */
				if (sorted_node->n > check_node->n)
				{
					check_node->next = sorted_node;
					check_node->prev = sorted_node->prev;
					current_node->prev->next = current_node->next;
					current_node->next->prev = current_node->prev;
					/* free the current node and set it back to the head node*/
					print_list(*list);
					free(current_node);
					current_node = (*list);
				}
			}
		}
	}
}
