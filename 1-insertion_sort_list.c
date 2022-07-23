#include "sort.h"
void display(listint_t *);
void exchangeData(listint_t *, listint_t *);
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: DLL list
 *
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *cur_list;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;
	cur_list = (*list);

	while (cur_list->next != NULL)
	{
		if (cur_list->n > cur_list->next->n)
			exchangeData(cur_list, (*list));
		else
			cur_list = cur_list->next;
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
/**
 * display - display ddl list
 * @head: list fo dll node
 */
void display(listint_t *head)
{
	listint_t *trav;

	trav = head;
	while (trav->prev != NULL)
		trav = trav->prev;
	print_list(trav);

}
/**
 * exchangeData - Exchange two nodes tail and head position
 * @list: list
 * @temp: temp list
 **/
void exchangeData(listint_t *list, listint_t *temp)
{
	temp = list->prev;
	if (temp != NULL)
	{
		temp->next = list->next;
		list->next->prev = temp;
	}
	else
		list->next->prev = NULL;
	list->prev = list->next;
	if (list->next->next != NULL)
	{
		list->next = list->next->next;
		list->prev->next = list;
		list->next->prev = list;
	}
	else
	{
		list->next->next = list;
		list->next = NULL;
	}
	display(list);
	while (list->prev != NULL)
	{
		if (list->n < list->prev->n)
		{
			temp = list->prev->prev;
			list->prev->next = list->next;
			list->next = list->prev;
			list->prev->prev = list;
			list->prev = temp;
			list->next->next->prev = list->next;
			if (temp != NULL)
				temp->next = list;
			display(list);
		}
		else
			list = list->prev;
	}
}
