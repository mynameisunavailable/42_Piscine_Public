#include <stdlib.h>
#include "ft_list.h"

#define true 1
#define false 0

void    ft_swap_list_data(t_list **a, t_list **b)
{
    void	*temp;

    temp = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = temp;
}

void	ft_reverse_go(t_list **left, t_list *begin_list_r, int *stop)
{
	if (begin_list_r->next)
		ft_reverse_go(left, begin_list_r->next, stop);
	if (*stop == true)
		return ;
	if ((*left == begin_list_r) || (*left == begin_list_r->next))
	{
		*stop = true;
		return ;
	}
	ft_swap_list_data(&(*left), &begin_list_r);
	*left = (*left)->next;
}

void ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*left;
	int		stop;
	
	left = begin_list;
	stop = false;
	ft_reverse_go(&left, begin_list, &stop);
}

#include <stdio.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	free_fct(void *data)
{
	free(data);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    char *dest_start;
    
    dest_start = dest;
    while(*src)
        *dest++ = *src++;
    *dest = '\0';
    return(dest_start);
}

void	ft_print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("Node %d: %s\n", i, list->data);
		list = list->next;
		i++;
	}
	
}

int main()
{
	char	*str1 = ft_strdup("1");
	t_list	*list = ft_create_elem(str1);
	char	*str2 = ft_strdup("2");
	ft_list_push_front(&list, str2);
	char	*str3 = ft_strdup("3");
	ft_list_push_front(&list, str3);
	char	*str4 = ft_strdup("4");
	ft_list_push_front(&list, str4);

	char	*cmp_str = "4";

	printf("current list:\n");
	ft_print_list(list);

	ft_list_reverse_fun(list);
	
	printf("processed list:\n");
	ft_print_list(list);
	
	return (0);
}


		// printf("ln %d: %s\n", l, ln->data);
		// printf("rn %d: %s\n", r, rn->data);