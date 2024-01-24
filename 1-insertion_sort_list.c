#include "sort.h"

/**
 * swap - switches the position of two array elements
 * @x: the first element
 * @y: the second element
 * Return: nothing
*/
void swap(int x, int y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: the doubly linked list
 * Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *check_node, *next_node;

	if (*list == NULL || list == NULL || (*list)->next || NULL)
		return;

	/* set head to current */
	current = (*list);

	/* loop from the second node to the last node */
	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		check_node = current->prev;

		/* loop and insert node in the sorted part*/
		while (check_node != NULL && current->n < check_node->n)
		{
			check_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = check_node;
			current->prev = check_node->prev;
			current->next = check_node;

			if (check_node->prev != NULL)
				check_node->prev->next = current;
			else
				*list = current;
			check_node->prev = current;
			check_node = current->prev;
		}
	}
}
