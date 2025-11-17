#include <stdlib.h>
#include "ft_list.h"

// void	free_fct(void *data)
// {
// 	free(data);
// }

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *temp;

	while (begin_list)
	{
		free_fct(begin_list->data);
		temp = begin_list;
		begin_list = begin_list->next;
		free(temp);
	}	
}