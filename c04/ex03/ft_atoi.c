/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:39:49 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 15:33:18 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi("   ---+--+1234ab567"));// return -1234
// 	printf("%d\n", ft_atoi("   ---+--+0ab56")); // return 0
// 	printf("%d\n", ft_atoi("   ---+-+01234ab56"));//return +1234
// }
