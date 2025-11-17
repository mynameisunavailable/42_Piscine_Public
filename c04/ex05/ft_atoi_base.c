/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:31:36 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/11 13:57:18 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

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

int	ft_check_signs_and_space(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
		{
			return (1);
		}
		if (*base == ' ' || *base == '\f' || *base == '\n'
			|| *base == '\r' || *base == '\t' || *base == '\v')
			return (1);
		base++;
	}
	return (0);
}

//check base char position in base_str and * by base_len
long	ft_check_char_pos_in_str(char *str, char *base_str)
{
	int		count;
	int		base_len;
	long	result;

	base_len = ft_strlen(base_str);
	result = 0;
	while (*str)
	{
		count = 0;
		while (base_str[count] && *str != base_str[count])
			count++;
		if (base_str[count] == '\0')
			break ;
		result = result * base_len + count;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	char	*start;
	int		negative;

	start = base;
	if (ft_strlen(base) <= 1)
		return (0);
	while (*start)
	{
		if (ft_check_duplicate_char(*start, start + 1) == 1)
			return (0);
		start++;
	}
	if (ft_check_signs_and_space(base) == 1)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	negative = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -negative;
		str++;
	}
	return (negative * ft_check_char_pos_in_str(str, base));
}
// #include <stdio.h>
// int main()
// {
// 	int i = ft_atoi_base("  -+-GBB", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base(" -\t-+-3BB", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("12Z3", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base(" \t--+80000000", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("-7FFFFFFF", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("3B9ACA00", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("-3B9ACA00", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("0", "0123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("2A", "01123456789ABCDEF");
// 	printf("%d\n", i);
// 	i = ft_atoi_base("2A", "01+23456789ABCDEF");
// 	printf("%d\n", i);
// }
