/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:01 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:19:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb = nb - 1;
	}
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_iterative_factorial(-3));
// 	printf("%d\n", ft_iterative_factorial(0));
// 	printf("%d\n", ft_iterative_factorial(1));
// 	printf("%d\n", ft_iterative_factorial(2));
// 	printf("%d\n", ft_iterative_factorial(10));
// 	printf("%d\n", ft_iterative_factorial(5));
// }
