/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:58 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:20:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_recursive_power(0,3));
// 	printf("%d\n", ft_recursive_power(1,3));
// 	printf("%d\n", ft_recursive_power(2,3));
// 	printf("%d\n", ft_recursive_power(10,3));
// 	printf("%d\n", ft_recursive_power(5,3));
// 	printf("%d\n", ft_recursive_power(0,0));
// 	printf("%d\n", ft_recursive_power(3,-3));
// 	printf("%d\n", ft_recursive_power(4,1));
// }
