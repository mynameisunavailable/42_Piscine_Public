#include <stdlib.h>
#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list **cpy;

	cpy = begin_list1;
	while (*cpy)
	{
		cpy = &(*cpy)->next;
	}
	*cpy = begin_list2;	
}