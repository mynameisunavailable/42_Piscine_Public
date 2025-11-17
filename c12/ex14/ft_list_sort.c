#include <stdlib.h>
#include "ft_list.h"

#define true 1
#define false 0

void	ft_swap_list_adr(t_list **a, t_list **b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *a;
	temp2 = (*b)->next;
	*a = *b; 
	(*a)->next = temp1;
	((*a)->next)->next = temp2;
}

// void ft_list_sort(t_list **begin_list, int (*cmp)(char *str1, char *str2))
void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	**cpy;
	void	*data1;
	void	*data2;
	int		swapped;

	if (!begin_list || !(*begin_list))
		return ;
	swapped = true;
	while (swapped == true)
	{
		swapped = false;
		cpy = begin_list;
		while ((*cpy)->next)
		{
			data1 = (*cpy)->data;
			data2 = ((*cpy)->next)->data;
			if (cmp(data1, data2) > 0)
			{
				ft_swap_list_adr(cpy, &((*cpy)->next));
				swapped = true;
			}
			cpy = &(*cpy)->next;
		}
	}
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
	
	printf("current list1:\n");
	ft_print_list(list);
	ft_list_sort(&list, &ft_strcmp);
	printf("processed list1:\n");
	ft_print_list(list);
	
	// t_list	*list2 = ft_create_elem(NULL);
	t_list	*list2 = NULL;
	printf("current list2:\n");
	ft_print_list(list2);
	ft_list_sort(NULL, &ft_strcmp);
	// ft_list_sort(&list2, &ft_strcmp);
	printf("processed list2:\n");
	ft_print_list(list2);
	
	return (0);
}

// void ft_list_sort(t_list **begin_list, 
// 	// int (*cmp)()
// 	int (*cmp)(char *str1, char *str2)
// )
// {
// 	t_list	**cpy;
// 	void	*data1;
// 	void	*data2;
// 	int		swapped;

// 	swapped = true;
// 	while (swapped == true)
// 	{
// 		swapped = false;
// 		cpy = begin_list;
// 		while ((*cpy)->next)
// 		{
// 			data1 = (*cpy)->data;
// 			data2 = ((*cpy)->next)->data;
// 			//print
// 			printf("processing:\n");
// 			printf("data1: %s, %p\n", (*cpy)->data, (*cpy)->next);
// 			printf("data2: %s, %p\n", ((*cpy)->next)->data, ((*cpy)->next)->next);
			
// 			if (cmp(data1, data2) > 0)
// 			{
// 				ft_swap_list_adr(cpy, &((*cpy)->next));
// 				// t_list	*temp;
// 				// t_list	*temp2;
// 				// temp = *cpy;
// 				// temp2 = ((*cpy)->next)->next;
// 				// *cpy = (*cpy)->next;
// 				// (*cpy)->next = temp;
// 				// (temp)->next = temp2;

// 				//print
// 				printf("swapped:\n");
// 				printf("data1: %s, %p\n", (*cpy)->data, (*cpy)->next);
// 				printf("data2: %s, %p\n", ((*cpy)->next)->data, ((*cpy)->next)->next);
				
// 				swapped = true;
// 			}
// 			cpy = &(*cpy)->next;
// 			ft_print_list(*begin_list);
// 		}
// 	}
// }
