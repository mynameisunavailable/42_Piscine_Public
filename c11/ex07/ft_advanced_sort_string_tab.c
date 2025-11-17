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

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_str(&tab[i], &tab[i + 1]);
				swapped = true;
			}
			i++;
		}	
	}	
}