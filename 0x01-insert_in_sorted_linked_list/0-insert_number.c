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
	listint_t *Next_node;
	listint_t *current;

	/* new node creation */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	/* case 0 :Empty list */
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	/* case 1: Insertion as a first node*/
	if ((*head)->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	/* casual case*/
	current = *head;

	while (current->next != NULL && current->next->n <= number)
		current = current->next;

	Next_node = current->next;
	current->next = new;
	new->next = Next_node;
	return (new);
}
