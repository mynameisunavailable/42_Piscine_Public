#include <stdlib.h>
#include "string/ft_string.h"
#include "utils/ft_utils.h"

void	ft_bubble_sort_from_n(char ***arr, int arr_c, size_t n)
{
	int	count;
	int	swapped;

	count = n;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		count = n;
		while (count + 1 < arr_c)
		{
			if (ft_strcmp((*arr)[count], (*arr)[count + 1]) > 0)
			{
				ft_swap_str(&((*arr)[count]), &((*arr)[count + 1]));
				swapped = 1;
			}
			count++;
		}		
	}
}