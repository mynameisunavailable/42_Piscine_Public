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

//insert behind the current list item
void	ft_list_push_insitu(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = (*begin_list)->next;
	(*begin_list)->next = elem;
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_create_elem(data);
	
	first->next = *begin_list;
	*begin_list = first;
}

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(char *, char *))
// void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	**curr;

	if (!begin_list)
		return ;
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	curr = begin_list;
	while ((*curr)->next)
	{
		if (cmp(((*curr)->data), data) > 0)
		{
			ft_list_push_front(curr, data);
			return ;
		}
		curr = &(*curr)->next;
	}
	if (cmp(((*curr)->data), data) > 0)
	{
		ft_list_push_front(curr, data);
		return ;
	}
	ft_list_push_insitu(curr, data);
}

#include <stdio.h>

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
	char	*str1 = ft_strdup("8");
	t_list	*list = ft_create_elem(str1);
	char	*str2 = ft_strdup("6");
	ft_list_push_front(&list, str2);
	char	*str3 = ft_strdup("4");
	ft_list_push_front(&list, str3);
	char	*str4 = ft_strdup("2");
	ft_list_push_front(&list, str4);
	t_list	*list2 = NULL;

	char	*cmp_str = "4";

	printf("current list:\n");
	ft_print_list(list);
	// ft_sorted_list_insert(&list, "1", ft_strcmp);
	// ft_sorted_list_insert(&list, "3", ft_strcmp);
	// ft_sorted_list_insert(&list, "7", ft_strcmp);
	// ft_sorted_list_insert(&list, "8", ft_strcmp);
	ft_sorted_list_insert(&list, "9", ft_strcmp);
	printf("processed list:\n");
	ft_print_list(list);
	
	ft_sorted_list_insert(NULL, "1", ft_strcmp);
	printf("current list:\n");
	ft_print_list(list2);
	ft_sorted_list_insert(&list2, "9", ft_strcmp);
	printf("processed list:\n");
	ft_print_list(list2);

	return (0);
}
