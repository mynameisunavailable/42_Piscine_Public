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

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	bitmask_ckrep(char* word, unsigned char* mask)
{
	unsigned char *c;
	
    while (*word)
    {
		c = (unsigned char *)word;
        if ((mask[*c / 8]) & (1U << (*c % 8)))
            return (1);
        else
            mask[*c / 8] = mask[*c / 8] | (1U << (*c % 8));
        word++;
    }
    return (0);
}

int	ft_is_white_space(char base)
{
	if (base == ' ' || base == '\f' || base == '\n'
		|| base == '\r' || base == '\t' || base == '\v')
		return (1);
	return (0);
}

int	base_to_int(char *str, char *base)
{
	int	i;
	int	res;
	int	base_len;

	base_len = ft_strlen(base);
	res = 0;
	while (*str)
	{
		i = 0;
		while (i < base_len && base[i] != *str)
			i++;
		if (i == base_len)
			break;
		res = res * base_len + i;
		str++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned char	mask[32] = {0};
	int				i;
	int				negative;

	if (ft_strlen(base) <= 1 || bitmask_ckrep(base, mask))
		return (0);
	i = 0;
	while (i < ft_strlen(base))
	{
		if (ft_is_white_space(base[i]) || base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	while (ft_is_white_space(*str))
		str++;
	negative = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = -negative;
	}
	return (negative * base_to_int(str, base));
}

#include <stdio.h>
int main()
{
	int i = ft_atoi_base("  -+-GBB", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base(" --+-3BB", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("12Z3", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base(" \t--+80000000", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("-7FFFFFFF", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("3B9ACA00", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("-3B9ACA00", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("0", "0123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("2A", "01123456789ABCDEF");
	printf("%d\n", i);
	i = ft_atoi_base("2A", "01+23456789ABCDEF");
	printf("%d\n", i);
}
