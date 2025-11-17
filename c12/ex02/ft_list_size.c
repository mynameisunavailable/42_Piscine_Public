#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int	c;

	c = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		c++;
	}
	return (c);
}