#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - function that  that inserts a number into
 **a sorted singly linked list.
 * @head: pointer to pointer to head of list.
 * @number: integer to be included in new node.
 * Return: Address of inserted node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current = *head;
	listint_t *Next = NULL;

	while (1)
	{
		if (current->n <= number && current->next->n > number)
		{
			break;
		}
		current = current->next;
	}

	/* printf("****%d\n", current->n); */
	new = malloc(sizeof(listint_t));
	Next = current->next;
	current->next = new;
	new->next = Next;
	new->n = number;
	return (new);
}
