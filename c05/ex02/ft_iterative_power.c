/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:34 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:19:39 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_iterative_power(0,3));
// 	printf("%d\n", ft_iterative_power(1,3));
// 	printf("%d\n", ft_iterative_power(2,3));
// 	printf("%d\n", ft_iterative_power(10,3));
// 	printf("%d\n", ft_iterative_power(5,3));
// }
