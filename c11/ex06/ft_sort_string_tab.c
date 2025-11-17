#include <stddef.h>

#define true 1
#define false 0

void    ft_swap_str(char **a, char **b)
{
    char *temp;

    temp = *a;
    *a = *b;
    *b = temp;
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

void ft_sort_string_tab(char **tab)
{
	int	i;
	int	swapped;

	swapped = true;
	while (swapped == true)
	{
		swapped = false;
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_str(&tab[i], &tab[i + 1]);
				swapped = true;
			}
			i++;
		}	
	}	
}

// #include <stdio.h>
// int main()
// {
// 	char *tab[] = {"string", "is ", "cat", "nip", NULL};
// 	ft_sort_string_tab(tab);
// 	int i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s", tab[i]);
// 		i++;
// 	}
// }