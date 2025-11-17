#include <stdlib.h>
#include "ft_list.h"

// void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
// 	int (*cmp)(char *, char *))
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	**curr;
	t_list	*temp2;

	if (!begin_list1)
		return ;
	curr = begin_list1;
	while (*curr && begin_list2)
	{
		if (cmp((*curr)->data, begin_list2->data) > 0)
		{
			temp2 = begin_list2;
			begin_list2 = begin_list2->next;
			temp2->next = *curr;
			*curr = temp2;
		}
		else
			curr = &(*curr)->next;
	}
	if (begin_list2)
	{
		*curr = begin_list2;
	}	
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

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list	*res;
	int		i;

	res = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&res, strs[i]);
		i++;
	}
	return (res);
}

int main()
{
	char	*str1[] = {"8", "6", "4", "2"};
	t_list	*list1 = ft_list_push_strs(4, str1);
	char	*str2[] = {"7", "5", "3", "1"};
	t_list	*list2 = ft_list_push_strs(4, str2);

	printf("list1:\n");
	ft_print_list(list1);
	printf("list2:\n");
	ft_print_list(list2);
	ft_sorted_list_merge(&list1, list2, ft_strcmp);
	printf("processed list:\n");
	ft_print_list(list1);
	
	char	*str3[] = {"7", "5", "3", "1"};
	t_list	*list3 = ft_list_push_strs(4, str3);
	char	*str4[] = {"8", "6", "4", "2"};
	t_list	*list4 = ft_list_push_strs(4, str4);

	printf("list3:\n");
	ft_print_list(list3);
	printf("list4:\n");
	ft_print_list(list4);
	ft_sorted_list_merge(&list3, list4, ft_strcmp);
	printf("processed list:\n");
	ft_print_list(list3);

	return (0);
}
