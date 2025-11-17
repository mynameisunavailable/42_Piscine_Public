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

void ft_list_clear_t_list(t_list *begin_list)
{
	t_list *temp;

	while (begin_list)
	{
		temp = begin_list;
		begin_list = begin_list->next;
		free(temp);
	}	
}

void ft_list_reverse(t_list **begin_list)
{
	t_list	*last;
	t_list	*og_start;

	og_start = *begin_list;
	last = ft_create_elem((*begin_list)->data);
	*begin_list = (*begin_list)->next;
	while (*begin_list)
	{
		ft_list_push_front(&last, (*begin_list)->data);
		*begin_list = (*begin_list)->next;
	}
	*begin_list = last;
	ft_list_clear_t_list(og_start);
}



// #include <stdio.h>
// #include <string.h>

// void	free_fct(void *data)
// {
// 	free(data);
// }

// void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
// {
// 	t_list *temp;

// 	while (begin_list)
// 	{
// 		free_fct(begin_list->data);
// 		temp = begin_list;
// 		begin_list = begin_list->next;
// 		free(temp);
// 	}	
// }

// void	print_list(t_list *list)
// {
// 	int i = 0;
// 	while (list)
// 	{
// 		printf("Node %d: %s\n", i, (char *)list->data);
// 		list = list->next;
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_list	*list = NULL;

// 	// 创建链表元素
// 	ft_list_push_front(&list, strdup("three"));
// 	ft_list_push_front(&list, strdup("two"));
// 	ft_list_push_front(&list, strdup("one"));

// 	printf("Original list:\n");
// 	print_list(list);

// 	ft_list_reverse(&list);

// 	printf("\nReversed list:\n");
// 	print_list(list);

// 	ft_list_clear(list, free_fct);
// 	return (0);
// }
