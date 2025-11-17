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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	write(1, "\n", 1);
}

//swaps pointer of the string
void	ft_swap_str_ptr(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//if s1 < s2 then negative, s1 > s2 then positive, same then 0
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
		{
			return (*s1 - *s2);
		}
		else if (*s2 > *s1)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0' || *s2 == '\0')
		return (*s1 - *s2);
	return (0);
}

int	main(int argc, char **argv)
{
	int	count;
	int	swapped;

	while (1)
	{
		swapped = 0;
		count = 1;
		while (count + 1 < argc)
		{
			if (ft_strcmp(argv[count], argv[count + 1]) > 0)
			{
				ft_swap_str_ptr(&argv[count], &argv[count + 1]);
				swapped = 1;
			}
			count++;
		}
		if (swapped == 0)
			break ;
	}
	count = 0;
	while (argc - 1 > count++)
	{
		ft_print_str(argv[count]);
	}
	return (0);
}
