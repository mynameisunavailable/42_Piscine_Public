#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *first;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	
	first->data = data;
	first->next = NULL;

	return (first);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_create_elem(data);
	
	first->next = *begin_list;
	*begin_list = first;
}

t_list *ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *last;
	t_list *temp;

	if (*begin_list == NULL)
	{
		ft_list_push_front(begin_list, data);
		return ;
	}
	else
	{
		temp = ft_list_last(*begin_list);
		last = ft_create_elem(data);
		(temp)->next = last;
	}	
}