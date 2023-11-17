#include "sort.h"

/**
 * swapping - this swaps the nodes
 * @a: the first node
 * @b: the second node
 * Return: void
 */
void swapping(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using swapping
 * @list: dl list of ints to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *x;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		x = i;
		i = i->next;

		while (x->prev && x->n < x->prev->n)
		{
			swapping(x->prev, x);
			if (!x->prev)
				*list = x;
			print_list(*list);
		}

	}
}
