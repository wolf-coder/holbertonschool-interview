#include "lists.h"

/**
* is_palindrome - Checks if a singly linked list is a palindrome.
* @head: Pointer to list Head node.
* Return: 0 if it is not a palindrome, 1 if it is a palindrome.
*/

int is_palindrome(listint_t **head)
{
	listint_t *P1, *P2, *prev, *next_n;

	if (!head || !*head)
		return (1);

	P1 = P2 = *head;

	while (P2 && P2->next)
	{
		P1 = P1->next;
		P2 = P2->next->next;
	}

	prev = NULL;
	P2 = *head;

	/* First Break check*/

	while (P1)
	{
		next_n = P1->next;
		P1->next = prev;
		prev = P1;
		if (!next_n)
			break;
		P1 = next_n;
	}

	/* Second Check */

	while (P1)
	{
		if (P2->n != P1->n)
			return (0);
		P1 = P1->next;
		P2 = P2->next;
	}

	return (1);
}
