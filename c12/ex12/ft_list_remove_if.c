#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*temp;

	prev = NULL;
	while (*begin_list)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			free_fct((*begin_list)->data);
			temp = *begin_list;
			*begin_list = (*begin_list)->next;
			free(temp);
			if (!*begin_list)
				prev->next = *begin_list;
		}
		else
		{
			if (prev)
				prev->next = *begin_list;
			prev = *begin_list;
			*begin_list = (*begin_list)->next;
		}
	}
}