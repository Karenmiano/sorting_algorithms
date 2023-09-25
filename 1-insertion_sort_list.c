#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list by insertion
 * @list: pointer to pointer to head node
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2, *temp1, *temp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node1 = (*list)->next;
	while (node1 != NULL)
	{
		node2 = node1;
		node1 = node1->next;
		while (node2->prev != NULL)
		{
			if (node2->n < node2->prev->n)
			{
				temp1 = node2->next;
				temp2 = node2->prev->prev;
				node2->next = node2->prev;
				node2->prev->next = temp1;
				node2->prev = temp2;
				node2->next->prev = node2;
				if (temp1 != NULL)
					temp1->prev = node2->next;
				if (temp2 != NULL)
					temp2->next = node2;
				else
					*list = node2;
				print_list(*list);
			}
			else
				break;
		}
	}
}
