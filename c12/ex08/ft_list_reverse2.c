#include <stdlib.h>
#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*go;

	temp = NULL;
	while (*begin_list)
	{
		go = (*begin_list)->next;
		(*begin_list)->next = temp;
		temp = *begin_list;
		*begin_list = go;
	}
	*begin_list = temp;
}

// #include <stdio.h>
// #include <string.h>

// t_list *ft_create_elem(void *data);
// void ft_list_push_front(t_list **begin_list, void *data);
// void ft_list_reverse(t_list **begin_list);
// void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

// t_list *ft_create_elem(void *data)
// {
// 	t_list *first;

// 	first = malloc(sizeof(t_list));
// 	if (!first)
// 		return (NULL);
	
// 	first->data = data;
// 	first->next = NULL;

// 	return (first);
// }

// void	ft_list_push_front(t_list **begin_list, void *data)
// {
// 	t_list	*first;

// 	first = ft_create_elem(data);
// 	first->next = *begin_list;
// 	*begin_list = first;
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

// void	free_fct(void *data)
// {
// 	free(data);
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
// 	ft_list_push_front(&list, strdup("four"));
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
