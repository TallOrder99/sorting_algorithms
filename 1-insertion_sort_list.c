#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked
 * list of integers in ascending order using the Insertion sort algorithm.
 * @list: The list.
 *
 * Return: Nothing.
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	int c;

	if (!list || !*list)
		return;
	temp = *list;
	while (temp->next)
	{
		c = 1;
		if (temp->n > temp->next->n)
		{
			if(!temp->prev)
			{
				if (!temp->next->next)
				{
					temp->next->next = temp;
					temp->next->prev = NULL;
					temp->prev = temp->next;
					temp->next = NULL;
				}
				else
				{
					temp->next = temp->next->next;
					temp->next->prev->next = temp;
					temp->next->prev->prev = NULL;
					temp->prev = temp->next->prev;
					temp->next->prev = temp;
				}
				*list = temp->prev;
				temp = temp->prev;
			}
			else if ((temp->next->next) && (temp->prev))
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp->next->next->prev = temp;
				temp->next = temp->next->next;
				temp->prev->next->next = temp;
				temp->prev = temp->prev->next;
				temp = temp->prev;
				if (temp->prev->n > temp->n)
				{
					if (temp->prev->prev)
						temp = temp->prev->prev;
					else
					{
						temp = temp->prev;
						c = 2;
					}
				}
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->next = temp;
				temp->next->prev = temp->prev;
				temp->prev = temp->next;
				temp->next = NULL;
				temp = temp->prev;
				if (temp->prev->n > temp->n)
				{
					if (temp->prev->prev)
						temp = temp->prev->prev;
				}
			}
			print_list(*list);
		}
		if (c == 1)
			temp = temp->next;
	}
}
