/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:27:49 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/07 14:22:31 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

void	ft_num_to_2hex(unsigned int i)
{
	unsigned int	tens;
	unsigned int	ones;
	char			*hex_str;

	hex_str = "0123456789abcdef";
	tens = i / 16;
	ones = i % 16;
	write(1, &hex_str[tens], 1);
	write(1, &hex_str[ones], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || 126 < *str)
		{
			write(1, "\\", 1);
			ft_num_to_2hex((unsigned char)*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
