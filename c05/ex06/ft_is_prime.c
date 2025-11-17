/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:25:20 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:25:36 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//can use (count * count < nb)
// Example: Is 29 prime?
// √29 ≈ 5.38
// So check divisibility only with 2, 3, 4, 5
// If none divide it, then 29 is prime.
// No need to check 6, 7, ..., 28.
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
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_is_prime(-1));
// 	printf("%d\n", ft_is_prime(0));
// 	printf("%d\n", ft_is_prime(1));
// 	printf("%d\n", ft_is_prime(2));
// 	printf("%d\n", ft_is_prime(3));
// 	printf("%d\n", ft_is_prime(4));
// 	printf("%d\n", ft_is_prime(5));
// 	printf("%d\n", ft_is_prime(6));
// 	printf("%d\n", ft_is_prime(16));
// 	printf("%d\n", ft_is_prime(144));
// 	printf("%d\n", ft_is_prime(151));
// }
