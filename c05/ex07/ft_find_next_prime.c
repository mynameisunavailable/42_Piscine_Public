/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:25:50 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:26:13 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns 1 if the given number is a prime number and 0 if it is not
int	ft_is_prime(int nb)
{
	int	count;

	if (nb < 2)
		return (0);
	count = 2;
	while (count * count <= nb)
	{
		if (nb % count == 0)
			return (0);
		count++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_find_next_prime(-1));
// 	printf("%d\n", ft_find_next_prime(0));
// 	printf("%d\n", ft_find_next_prime(1));
// 	printf("%d\n", ft_find_next_prime(2));
// 	printf("%d\n", ft_find_next_prime(3));
// 	printf("%d\n", ft_find_next_prime(4));
// 	printf("%d\n", ft_find_next_prime(5));
// 	printf("%d\n", ft_find_next_prime(6));
// 	printf("%d\n", ft_find_next_prime(16));
// 	printf("%d\n", ft_find_next_prime(144));
// 	printf("%d\n", ft_find_next_prime(151));
// }
