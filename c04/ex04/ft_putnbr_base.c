/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:35:22 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/11 12:55:36 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_convert_to_base(long n, char *base, int base_size)
{
	if (n >= base_size)
	{
		ft_convert_to_base(n / base_size, base, base_size);
	}
	write(1, &base[n % base_size], 1);
	return ;
}

//checks the s1 string for duplicate of char c
int	ft_check_duplicate_char(char c, char *s1)
{
	while (*s1)
	{
		if (c == s1[0])
		{
			return (1);
		}
		s1++;
	}
	return (0);
}

int	ft_check_signs(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
		{
			return (1);
		}
		base++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	*start;
	char	chara;
	long	n;

	n = nbr;
	start = base;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return ;
	while (*start)
	{
		chara = *start;
		if ((ft_check_duplicate_char(chara, start + 1) == 1)
			|| (ft_check_signs(base) == 1))
			return ;
		start++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	ft_convert_to_base(n, base, base_len);
}

// int main()
// {
// 	ft_putnbr_base(16, "0123456789ABCDEF"); //10
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789ABCDEF"); //2A
// 	write(1, "\n", 1);
// 	ft_putnbr_base(955, "0123456789ABCDEF"); //3BB
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-955, "0113456789ABCDEF"); //-3BB
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "0123456789ABCDEF"); //
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483647, "0123456789ABCDEF"); //
// 	write(1, "\n", 1);
// 	// ft_putnbr_base(2147483648, "0123456789ABCDEF"); //
// 	// write(1, "\n", 1);
// 	ft_putnbr_base(1000000000, "0123456789ABCDEF"); //
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-1000000000, "0123456789ABCDEF"); //
// 	write(1, "\n", 1);
// 	ft_putnbr_base(0, "0123456789ABCDEF"); //

// 	return 0;
// }
