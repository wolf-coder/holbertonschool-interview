#include "search.h"



skiplist_t *linear_skip(skiplist_t *list, int value)
{

	skiplist_t *Tmp = list;

	if (!list)
		return (NULL);
	while (Tmp->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		 Tmp->express->index, Tmp->express->n);
		if (Tmp->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%ld]\n",
			 Tmp->index, Tmp->express->index);
			break;
		}
		Tmp = Tmp->express;
	}
	if (!Tmp->express)
	{
		for (list = Tmp; list->next != NULL; list = list->next)
		;
		printf("Value found between indexes [%lu] and [%ld]\n",
		 Tmp->index, list->index);
	}
	for (list = Tmp ; list != Tmp->express ; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		 list->index, list->n);
		if (value == list->n)
		{
			break;
		}
	}
	if (list == Tmp->express)
		return (NULL);
	else
		return (list);
}
