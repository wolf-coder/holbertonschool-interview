#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *check_cycle- A program that detect a loop within a given linked list.
 *
 *@list: A pointer to the head of a given list.
 *
 *Return: 0->No loop, 1 otherwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *p, *p2;

	if (list == NULL)
		return (0);
	p = list;
	p2 = list->next;
	while (p2 != NULL  && p2->next != NULL && p != NULL)
	{
		if (p == p2)
			return (1);
		p = p->next;
		p2 = p2->next->next;
	}
	return (0);
}
