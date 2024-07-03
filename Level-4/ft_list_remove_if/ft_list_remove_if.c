#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !data_ref || !cmp)
		return ;

	t_list *current = *begin_list;
	t_list *previous = NULL;


	while (current)
	{
		if (!(*cmp)((void*)current->data, (void*)data_ref))
		{
			if (previous == NULL)
				*begin_list = current->next;
			else
				previous->next = current->next;
			free(current);
		}
		else
		{
			previous->next = current;
			current = current->next;
		}
	}

}