#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	if (!lst || !cmp)
		return NULL;

	int temp;
	t_list *curr = lst;
	t_list *last_sort = NULL;
	int swapped = 0;

	while (1)
	{
		swapped = 0;
		curr = lst;
		while (curr->next != last_sort)
		{
			if ((*cmp)(curr->data, curr->next->data) == 0)
			{
				temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
				curr = lst;
			}
			else
				curr = curr->next;
		}
		last_sort = curr;

		if (!swapped)
			break ;
	}
	return lst;
}
