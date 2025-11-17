/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:57:35 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 18:29:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}	
}

void	ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
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

void	ft_bubble_sort_except_0(char ***arr, int arr_c)
{
	int	count;
	int	swapped;

	count = 1;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		count = 1;
		while (count + 1 < arr_c)
		{
			if (ft_strcmp((*arr)[count], (*arr)[count + 1]) > 0)
			{
				ft_swap(&((*arr)[count]), &((*arr)[count + 1]));
				swapped = 1;
			}
			count++;
		}		
	}
}

int	main(int argc, char **argv)
{
	int count;
	
	ft_bubble_sort_except_0(&argv, argc);
	count = 1;
	while (count < argc)
	{
		ft_put_str(argv[count]);
		ft_put_str("\n");
		count++;
	}
}
