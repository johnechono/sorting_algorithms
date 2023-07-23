#include "sort.h"

/**
 * _swap - will swap two nodes of doubly linked list
 * @node: node base to be changed
 * @list: the double linked list head
 * Return: None
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *temp2, *temp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	temp = temp3 = *node;
	temp2 = temp->next;

	temp->next = temp2->next;
	temp3 = temp->prev;
	temp->prev = temp2;
	temp2->next = temp;
	temp2->prev = temp3;

	if (temp2->prev)
		temp2->prev->next = temp2;

	if (temp->next)
		temp->next->prev = temp;

	*node = temp2;
}
/**
 * cocktail_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the cocktail shaker sort algorithm
 * @list: the head of list to be sorted
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
